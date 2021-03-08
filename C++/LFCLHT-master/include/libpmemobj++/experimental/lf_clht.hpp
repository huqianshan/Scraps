#ifndef PMEMOBJ_LFCLHT_HPP
#define PMEMOBJ_LFCLHT_HPP

#include <libpmemobj++/detail/common.hpp>
#include <libpmemobj++/detail/compound_pool_ptr.hpp>
#include <libpmemobj++/detail/template_helpers.hpp>
#include <libpmemobj++/experimental/concurrent_hash_map.hpp>
#include <libpmemobj++/experimental/hash.hpp>
#include <libpmemobj++/experimental/v.hpp>
#include <libpmemobj++/make_persistent.hpp>
#include <libpmemobj++/make_persistent_atomic.hpp>
#include <libpmemobj++/mutex.hpp>
#include <libpmemobj++/p.hpp>
#include <libpmemobj++/persistent_ptr.hpp>
#include <libpmemobj++/transaction.hpp>
#include <libpmemobj++/detail/persistent_pool_ptr.hpp>
#include <libpmemobj++/detail/specialization.hpp>

#include <atomic>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator> // for std::distance
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>
#include <time.h>
#include <type_traits>
#include <vector>
#include <immintrin.h>
#define LFCLHT_DEBUG 1
// bool __sync_val_compare_and_swap (type *ptr, type oldval, type newval)
/*
These builtins perform an atomic compare and swap. That is, if the current
value of *ptr is oldval, then write newval into *ptr. The "bool" version
returns true if the comparison is successful and newval was written.

NOTE: oldval will NOT be updated if the atomic operation fails.
*/
#define CAS(ptr, oldval, newval) \
    (__sync_bool_compare_and_swap(ptr, oldval, newval))

//test-and-set uint8_t
// set *addr to 0xFF and return the old value in addr
static inline uint8_t tas_uint8(volatile uint8_t *addr)
{
    uint8_t oldval;
    __asm__ __volatile__("xchgb %0,%1"
                         : "=q"(oldval), "=m"(*addr)
                         : "0"((unsigned char)0xff), "m"(*addr)
                         : "memory");
    return (uint8_t)oldval;
}

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define ALIGNED(N) __attribute__((aligned(N)))

#define CLHT_READ_ONLY_FAIL 1
#define CLHT_HELP_RESIZE 1
#define CLHT_PERC_EXPANSIONS 1
#define CLHT_MAX_EXPANSIONS 24
#define CLHT_PERC_FULL_DOUBLE 50 /* % */
#define CLHT_RATIO_DOUBLE 2
#define CLHT_OCCUP_AFTER_RES 40
#define CLHT_PERC_FULL_HALVE 5 /* % */
#define CLHT_RATIO_HALVE 8
#define CLHT_MIN_CLHT_SIZE 8
#define CLHT_DO_CHECK_STATUS 0
#define CLHT_DO_GC 0
#define CLHT_STATUS_INVOK 500000
#define CLHT_STATUS_INVOK_IN 500000
#define LOAD_FACTOR 2

#define CACHE_LINE_SIZE 64
#define ENTRIES_PER_BUCKET 6
//#define ENTRIES_PER_BUCKET    3

#define LOCK_FREE 0
#define LOCK_UPDATE 1
#define LOCK_RESIZE 2

std::mutex resize_bucket_num_mutex;
/*
自己增加的，初始值为最旧表的总bucket数
为0时表示多线程协同扩容完成，
每个扩容线程每次取固定数量的bucket进行扩容
多个扩容线程可以同时进行扩容操作。*/
pmem::obj::p<uint64_t> resize_bucket_num;

namespace pmem
{
    namespace obj
    {
        namespace experimental
        {

            using namespace pmem::obj;

            template <typename Key, typename T, typename Hash = std::hash<Key>,
                      typename KeyEqual = std::equal_to<Key>>
            class lfclht
            {
            public:
                using key_type = Key;
                using mapped_type = T;
                using value_type = std::pair<const Key, T>; // key and value core
                using size_type = size_t;
                using difference_type = ptrdiff_t;
                using pointer = value_type *;
                using const_pointer = const value_type *;
                using reference = value_type &;
                using const_reference = const value_type &;

                using hasher = Hash;
                using key_equal =
                    typename internal::key_equal_type<Hash, KeyEqual>::type;
                using atomic_backoff = internal::atomic_backoff; //功能类似于memory_pause()
                //core
                struct bucket_s;
                struct clht_hashtable_s;
                struct ht_ts; //感觉没有用起来，ts代表什么
                struct clht_meta;

                using hv_type = size_t;
                using partial_t = uint16_t;           //最高2字节为fingerprints，参考FPTree和clevel hashing
                using clht_lock_t = volatile uint8_t; //锁是易失性的，防止线程死掉后其他线程无法访问
                using kv_ptr_t = detail::compound_pool_ptr<value_type>;
                using bucket_ptr_t = detail::compound_pool_ptr<bucket_s>;
                using clht_hashtable_ptr_t = detail::compound_pool_ptr<clht_hashtable_s>;
                using ht_ts_ptr_t = detail::compound_pool_ptr<ht_ts>;
                using clht_table_t = persistent_ptr<bucket_s[]>;
                using clht_meta_ptr_t = detail::compound_pool_ptr<clht_meta>;
                //partial_t for optane dc pmm
                constexpr static size_type partial_ext_bits = (sizeof(uint64_t) - sizeof(partial_t)) * 8;

                struct ret
                {
                    bool found;
                    difference_type bucket_idx;
                    uint8_t step;
                    uint8_t slot_idx;
                    bool expanded;
                    uint64_t capacity;

                    ret(difference_type _bucket_idx, uint8_t _step, uint8_t _slot_idx,
                        size_type _expanded = false, uint64_t _cap = 0)
                        : found(true), bucket_idx(_bucket_idx), step(_step),
                          slot_idx(_slot_idx), expanded(_expanded), capacity(_cap)
                    {
                    }

                    ret(bool _expanded, uint64_t _cap)
                        : found(false), bucket_idx(0), step(0), slot_idx(0),
                          expanded(_expanded), capacity(_cap)
                    {
                    }

                    ret(bool _found)
                        : found(_found), bucket_idx(0), step(0), slot_idx(0),
                          expanded(false), capacity(0)
                    {
                    }

                    ret()
                        : found(false), bucket_idx(0), step(0), slot_idx(0),
                          expanded(false), capacity(0)
                    {
                    }
                };

                struct ALIGNED(CACHE_LINE_SIZE) bucket_s
                {
                    //clht_lock_t lock;
                    volatile uint32_t hops;             //4 bytes
                    kv_ptr_t slots[ENTRIES_PER_BUCKET]; //下一步计划改成6slots/bucket
                    bucket_ptr_t next;

                    bucket_s()
                    {
                        //lock = LOCK_FREE;
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++) //rzxiao size_t j=0;
                        {
                            slots[j] = nullptr;
                        }
                        next = nullptr;
                    }
                };

                struct ALIGNED(CACHE_LINE_SIZE) clht_hashtable_s
                {
                    union
                    {
                        struct
                        {
                            size_t num_buckets;
                            clht_table_t table;
                            size_t hash;
                            size_t version;
                            uint8_t next_cache_line[CACHE_LINE_SIZE -
                                                    (3 * sizeof(size_t)) - (sizeof(clht_table_t))];
                            //core
                            clht_hashtable_ptr_t table_tmp;
                            clht_hashtable_ptr_t table_prev;
                            clht_hashtable_ptr_t table_new;
                            volatile uint32_t num_expands; // why volatile?
                            union
                            {
                                volatile uint32_t num_expands_threshold;
                                uint32_t num_buckets_prev;
                            };
                            volatile int32_t is_helper;
                            volatile int32_t helper_done;
                            size_t version_min;
                        };
                        uint8_t padding[2 * CACHE_LINE_SIZE];
                    };

                    clht_hashtable_s(uint64_t n_buckets = 0) : num_buckets(n_buckets)
                    {
                        table = make_persistent<bucket_s[]>(num_buckets);
                        hash = num_buckets - 1;
                        version = 0;
                        table_tmp = nullptr;
                        table_new = nullptr;
                        table_prev = nullptr;
                        num_expands = 0;
                        num_expands_threshold = (CLHT_PERC_EXPANSIONS * num_buckets); //默认扩展的bucket数达到总的bucket数1%进行扩容操作。
                        if (num_expands_threshold == 0)
                        {
                            num_expands_threshold = 1;
                        }
                        is_helper = 1;
                        helper_done = 0;
                    }
                };

                struct ALIGNED(CACHE_LINE_SIZE) ht_ts
                {
                    union
                    {
                        struct
                        {
                            size_t version;
                            clht_hashtable_ptr_t versionp;
                            int id;
                            ht_ts_ptr_t next;
                        };
                        uint8_t padding[CACHE_LINE_SIZE];
                    };
                };

                struct clht_meta
                {
                    clht_hashtable_ptr_t ht;
                    clht_hashtable_ptr_t ht_oldest;
                    ht_ts_ptr_t version_list;
                    size_t version_min;
                    p<bool> is_resizing;
                    clht_meta()
                    {
                        ht = NULL;
                        ht_oldest = NULL;
                        version_list = NULL;
                        version_min = 0;
                        is_resizing = false;
                    }
                    clht_meta(const clht_hashtable_ptr_t &ht1, const clht_hashtable_ptr_t &ht_oldest1,
                              const ht_ts_ptr_t &version_list1, size_t version_N, bool flag)
                    {
                        ht = ht1;
                        ht_oldest = ht_oldest1;
                        version_list = version_list1;
                        version_min = version_N;
                        is_resizing = flag;
                    }
                }; //结构体后面忘记加分号";"引发出了这么多问题呀;

                static partial_t
                get_partial(hv_type hv)
                {
                    constexpr static size_type shift_bits =
                        (sizeof(hv_type) - sizeof(partial_t)) * 8;
                    return (partial_t)((uint64_t)hv >> shift_bits);
                }

                lfclht(uint64_t n_buckets) : meta(make_persistent<clht_meta>().raw().off),
                                             thread_num(0)
                {
                    std::cout << "LF-CLHT n_buckets = " << n_buckets << std::endl;

                    // setup pool
                    PMEMoid oid = pmemobj_oid(this);
                    assert(!OID_IS_NULL(oid));
                    my_pool_uuid = oid.pool_uuid_lo;
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid)); //meta在访问前必须先创建，否则会报段错误
                    persistent_ptr<clht_hashtable_s> ht_tmp =
                        make_persistent<clht_hashtable_s>(n_buckets);
                    m->ht.off = ht_tmp.raw().off;
                    //std::cout<<"lfclht constructor debug line 0" << std::endl;
                    resize_lock = LOCK_FREE;
                    //        gc_lock = LOCK_FREE;
                    status_lock = LOCK_FREE;
                    m->version_list = NULL; //感觉没有用起来呀
                                            //std::cout<<"lfclht constructor debug line 1" << std::endl;

                    m->version_min = 0;
                    m->ht_oldest = m->ht;
                    //std::cout<<"lfclht constructor debug line 2" << std::endl;

                    m->is_resizing = false;
                    //std::cout<<"lfclht constructor debug line 3" << std::endl;
                    //没有持久化的感觉，不会有问题吗？
                    run_expand_thread.get_rw().store(true); //原子变量存储store指令，修改时采用get_rw函数
                }

                bucket_ptr_t
                clht_bucket_create_stats(pool_base &pop, clht_hashtable_s *ht_ptr,
                                         clht_meta_ptr_t &m_copy)
                {
                    clht_meta *m = static_cast<clht_meta *>(m_copy(my_pool_uuid)); //added
                    persistent_ptr<bucket_s> tmp;
                    make_persistent_atomic<bucket_s>(pop, tmp);
                    if (__sync_add_and_fetch(&ht_ptr->num_expands, 1) >=
                        ht_ptr->num_expands_threshold)
                        m->is_resizing = true; //是否需要更改？如果要更改，怎么改？
                    return bucket_ptr_t(tmp.raw().off);
                }

                /**
	            * Get the persistent memory pool where hashmap resides.
	            * @returns pmem::obj::pool_base object.
	            */
                pool_base
                get_pool_base()
                {
                    PMEMobjpool *pop =
                        pmemobj_pool_by_oid(PMEMoid{my_pool_uuid, 0});

                    return pool_base(pop);
                }

                void
                set_thread_num(size_type num)
                {
                    if (work_threads_num > 0)
                    {
                        // Reclaim the memory in persistent buffers allocated in previous
                        // round of set_thread_num.
                        for (size_type i = 0; i < work_threads_num; i++)
                        {
                            difference_type di = static_cast<difference_type>(i);
                            if (tmp_meta[di] != nullptr)
                                delete_persistent<clht_meta>(tmp_meta[di]); //存在即删除
                            if (tmp_entry[di] != nullptr)
                                delete_persistent<value_type>(tmp_entry[di]);
                        }
                        delete_persistent<persistent_ptr<clht_meta>[]>(tmp_meta, work_threads_num);
                        delete_persistent<persistent_ptr<value_type>[]>(tmp_entry, work_threads_num);
                    }

                    work_threads_num = num;

#ifdef LFCLHT_DEBUG
                    thread_logs.resize(work_threads_num); //vector重新调整大小
                    for (uint64_t i = 0; i < work_threads_num; i++)
                    {
                        if (!thread_logs[i].is_open())
                        {
                            std::stringstream ss;
                            ss << "thread-" << i << ".log";
                            thread_logs[i].open(ss.str(), std::fstream::out);
                        }
                    }
#endif
                    // Setup persistent buffers according to the thread_num.
                    tmp_meta = make_persistent<persistent_ptr<clht_meta>[]>(work_threads_num);
                    tmp_entry = make_persistent<persistent_ptr<value_type>[]>(work_threads_num);
                }

                /*
	bool
	get_lock(pool_base &pop, clht_lock_t *lock, clht_hashtable_s *ht_ptr)
	{
		clht_lock_t l;
		while ((l = CAS(lock, LOCK_FREE, LOCK_UPDATE)) == LOCK_UPDATE)
			atomic_backoff(); // pause for hot path

        if (l == LOCK_RESIZE)
        {
#if CLHT_HELP_RESIZE == 1
			ht_resize_help(ht_ptr);
#endif
			while (ht_ptr->table_new == nullptr)
                pop.drain();

            return false;
        }

        return true;
。	}

	bool
	lock_acq_resize(clht_lock_t *lock)
	{
		clht_lock_t l;
		while ((l = CAS(lock, LOCK_FREE, LOCK_RESIZE)) == LOCK_UPDATE)
			atomic_backoff(); // pause for hot path

		if (l == LOCK_RESIZE)
			return false;

		return true;
    } */

                uint8_t
                try_lock(pool_base &pop, clht_lock_t *lock)
                {
                    return tas_uint8(lock);
                }

                void
                unlock(pool_base &pop, clht_lock_t *lock)
                {
                    pop.drain();
                    *lock = LOCK_FREE;
                }

                ret
                get(const key_type &key) const
                {
                    hv_type hv = hasher{}(key);
                    clht_meta_ptr_t m_copy(meta);                                  //new added
                    clht_meta *m = static_cast<clht_meta *>(m_copy(my_pool_uuid)); //new added
                    clht_hashtable_s *ht_ptr = m->ht.get_address(my_pool_uuid);
                    difference_type idx = static_cast<difference_type>(
                        hv % static_cast<hv_type>(ht_ptr->num_buckets));
                    bucket_s *bucket = &ht_ptr->table[idx];
                    uint8_t step = 0;

                    do
                    {
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                        { //如果需要加入partial key该如何做？
                            if (bucket->slots[j] != nullptr && key_equal{}(
                                                                   bucket->slots[j].get_address(my_pool_uuid)->first, key))
                                return ret(idx, step, j);
                        }

                        bucket = bucket->next.get_address(my_pool_uuid);
                        step++; //Number of steps jumped in bucket list --noted by rzxiao
                    } while (unlikely(bucket != nullptr));
                    //这里需要加一层控制逻辑，由于resizing原因，可能丢失了已插入的元素，造成找不到，需要re-search操作。
                    return ret();
                }

                bool
                key_exists(bucket_s *bucket, const key_type &key) const
                {
                    do
                    {
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                        {
                            if (bucket->slots[j] != nullptr && key_equal{}(
                                                                   bucket->slots[j].get_address(my_pool_uuid)->first, key))
                                return true;
                        }

                        bucket = bucket->next.get_address(my_pool_uuid);
                    } while (unlikely(bucket != nullptr));
                    return false;
                }

                static void
                allocate_KV_copy_construct(pool_base &pop,
                                           persistent_ptr<value_type> &KV_ptr,
                                           const void *param)
                {
                    const value_type *v = static_cast<const value_type *>(param);
                    internal::make_persistent_object<value_type>(pop, KV_ptr, *v);
                }

                static void
                allocate_KV_move_construct(pool_base &pop,
                                           persistent_ptr<value_type> &KV_ptr,
                                           const void *param)
                { //转移拷贝
                    const value_type *v = static_cast<const value_type *>(param);
                    internal::make_persistent_object<value_type>(
                        pop, KV_ptr, std::move(*const_cast<value_type *>(v)));
                }

                ret
                put(const value_type &value, size_type thread_id, size_type id)
                {
                    return generic_insert(value.first, &value,
                                          allocate_KV_copy_construct, thread_id, id);
                }

                ret
                put(value_type &&value, size_type thread_id, size_type id)
                { //value为&&，对应移动拷贝
                    return generic_insert(value.first, &value,
                                          allocate_KV_move_construct, thread_id, id);
                }

                // bool
                ret
                generic_insert(const key_type &key, const void *param,
                               void (*allocate_KV)(pool_base &, persistent_ptr<value_type> &,
                                                   const void *),
                               size_type thread_id, size_type id)
                {
                    pool_base pop = get_pool_base();
                    //std::cout << "generic insert tag 0 "<<std::endl;
                    difference_type t_id = static_cast<difference_type>(thread_id);
                    //std::cout << "generic insert tag 0.1 "<<std::endl;

                    allocate_KV(pop, tmp_entry[t_id], param);
                    //std::cout << "generic insert tag 0.2 "<<std::endl;

                    kv_ptr_t created(tmp_entry[t_id].raw().off);
                    //std::cout << "generic insert tag 1 "<<std::endl;

                    /*
	    clht_hashtable_s *ht_ptr = ht.get_address(my_pool_uuid);
	    hv_type hv = hasher{}(key);
	    difference_type idx = static_cast<difference_type>(
            hv % static_cast<hv_type>(ht_ptr->num_buckets));
	    bucket_s *bucket = &ht_ptr->table[idx];
*/
                    bool expanded = false;
                    uint64_t initial_capacity = 0;

#ifdef LFCLHT_DEBUG
                    uint64_t retry_insert_cnt = 0;
                    //std::cout << "generic insert tag 1.1 "<<std::endl;

                    //		thread_logs[thread_id] << "Thread-" << thread_id << " starts inserting " /*<< key */<< std::endl;
                    //std::cout << "generic insert tag 1.2 "<<std::endl;

#endif

#ifdef DEBUG_RESIZING
                    initial_capacity = capacity();
#endif
                    /*
#if CLHT_READ_ONLY_FAIL == 1
	    if (key_exists(bucket, key))
		    return ret(true);
#endif */
                    /*
        clht_lock_t *lock = &bucket->lock;
        while (!get_lock(pop, lock, ht_ptr))
        {
            ht_ptr = ht.get_address(my_pool_uuid);
            idx = static_cast<difference_type>(
                hv % static_cast<hv_type>(ht_ptr->num_buckets));
            bucket = &ht_ptr->table[idx];
            lock = &bucket->lock;
        }
 */
                    //while(true) { //added 20200905
                RETRY_INSERT:
#ifdef LFCLHT_DEBUG
                    retry_insert_cnt++;
                    if (retry_insert_cnt > 10)
                    {
                        thread_logs[thread_id] << "Thread-" << thread_id
                                               << " [loop] retry_insert_cnt = " << retry_insert_cnt
                                               /*	<< ", key = " << key */
                                               << std::endl;
                    }
                    else if (retry_insert_cnt > 1)
                    {
                        thread_logs[thread_id] << "Thread-" << thread_id
                                               << " retry_insert_cnt = " << retry_insert_cnt
                                               /*	<< ", key = " << key */
                                               << std::endl;
                    }
#endif
                    //std::cout << "generic insert tag 2 "<<std::endl;

                    clht_meta_ptr_t m_copy(meta);
                    pop.persist(&(meta.off), sizeof(uint64_t)); //防止元数据meta被更改了，需要先持久化

                    clht_meta *m = static_cast<clht_meta *>(m_copy(my_pool_uuid));

                    clht_hashtable_s *ht_ptr = m->ht.get_address(my_pool_uuid);
                    hv_type hv = hasher{}(key);
                    difference_type idx = static_cast<difference_type>(
                        hv % static_cast<hv_type>(ht_ptr->num_buckets));
                    bucket_s *bucket = &ht_ptr->table[idx];

                    if (key_exists(bucket, key))
                        return ret(true);
                    //std::cout << "generic insert tag 3 "<<std::endl;

                    kv_ptr_t *empty = nullptr;
                    do
                    {
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                        {
                            if (bucket->slots[j] != nullptr && key_equal{}(
                                                                   bucket->slots[j].get_address(my_pool_uuid)->first, key))
                            {
                                //			        unlock(pop, lock);
                                return ret(true);
                            }
                            else if (empty == nullptr && bucket->slots[j] == nullptr)
                                empty = &bucket->slots[j];
                        }
                        //std::cout << "generic insert tag 4 "<<std::endl;

                        //            int resize = 0;
                        if (likely(bucket->next == nullptr))
                        {
                            if (unlikely(empty == nullptr))
                            {
                                bucket_ptr_t b_new = clht_bucket_create_stats(pop,
                                                                              ht_ptr, m_copy); //传递m_copy 是否正确还是要传meta。
                                kv_ptr_t &s_new = b_new(my_pool_uuid)->slots[0];

                                s_new.off = created.raw();
                                pop.persist(&s_new.off, sizeof(kv_ptr_t));
                                if (CAS(&(bucket->next.off), /*nullptr*/ 0, b_new.raw()))
                                { //将nullptr改成数值0
                                    pop.persist(&bucket->next.off, sizeof(bucket_ptr_t));
                                }
                                else
                                {
#ifdef LFCLHT_DEBUG
                                    std::cout << "function-generic_insert line556 insertion, cas fails, bucket->next " << std::endl;
#endif
                                    goto RETRY_INSERT;
                                }
                            }
                            else
                            {
                                //                    empty->off = tmp_entry.raw().off;
                                kv_ptr_t old_empty = *empty;
                                if (CAS(&(empty->off), old_empty.raw(), created.raw()))
                                {
                                    pop.persist(&empty->off, sizeof(kv_ptr_t));
                                }
                                else
                                {
#ifdef LFCLHT_DEBUG
                                    std::cout << "insertion, cas fails, empty->off " << empty->off << std::endl;
#endif

                                    goto RETRY_INSERT;
                                }
                            }

                            //               unlock(pop, lock);
                            if (unlikely(!m->is_resizing && meta(my_pool_uuid)->is_resizing))
                            {
#ifdef DEBUG_RESIZING
                                expanded = true;
#endif
                                pop.persist(&(meta.off), sizeof(uint64_t));
                                // Start resizing... If crash, return true, because
                                // the insert anyway succeeded
                                if (ht_status(true /* is_increase */,
                                              false /* just_print */) == 0) //返回0表示故障了
                                    return ret(expanded, initial_capacity);
                            }
                            return ret(expanded, initial_capacity);
                        }
                        bucket = bucket->next.get_address(my_pool_uuid);
                    } while (true);
                    //	  }//added 20200905
                }

                ret
                erase(const key_type &key, size_type thread_id)
                {
                    pool_base pop = get_pool_base();
                    hv_type hv = hasher{}(key);
                    /*	    clht_hashtable_s *ht_ptr = ht.get_address(my_pool_uuid);
	    difference_type idx = static_cast<difference_type>(
		    hv % static_cast<hv_type>(ht_ptr->num_buckets));
	    bucket_s *bucket = &ht_ptr->table[idx];
	    uint8_t step = 0;

#if CLHT_READ_ONLY_FAIL == 1
        if (!key_exists(bucket, key))
            return ret();
#endif
*/
                    /*        clht_lock_t *lock = &bucket->lock;
        while (!get_lock(pop, lock, ht_ptr))
        {
            ht_ptr = ht.get_address(my_pool_uuid);
            idx = static_cast<difference_type>(
                hv % static_cast<hv_type>(ht_ptr->num_buckets));
            bucket = &ht_ptr->table[idx];
            lock = &bucket->lock;
        }
*/
                    while (true)
                    {
                        clht_meta_ptr_t m_copy(meta);
                        clht_meta *m = static_cast<clht_meta *>(m_copy(my_pool_uuid));
                        clht_hashtable_s *ht_ptr = m->ht.get_address(my_pool_uuid);
                        difference_type idx = static_cast<difference_type>(
                            hv % static_cast<hv_type>(ht_ptr->num_buckets));
                        bucket_s *bucket = &ht_ptr->table[idx];
                        uint8_t step = 0;
                        do
                        {
                            for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                            {
                                kv_ptr_t tmp(bucket->slots[j].off); //是否需要添加off
                                if (tmp.get_offset() != 0)
                                {
                                    //		                if (bucket->slots[j] != nullptr && key_equal{}(
                                    //		                    bucket->slots[j].get_address(my_pool_uuid)->first, key))
                                    if (key_equal{}(tmp.get_address(my_pool_uuid)->first, key))
                                    {
                                        if (CAS(&(bucket->slots[j].off), tmp.off, 0))
                                        {
                                            pop.persist(&(bucket->slots[j].off), sizeof(kv_ptr_t));
                                            //PMEMoid oid = bucket->slots[j].raw_ptr(my_pool_uuid);
                                            PMEMoid oid = tmp.raw_ptr(my_pool_uuid);
                                            pmemobj_free(&oid);

                                            //			                    bucket->slots[j] = nullptr;
                                            //pop.persist(&bucket->slots[j].off, sizeof(kv_ptr_t));

                                            //			                    unlock(pop, lock);
                                            if (m_copy == meta)
                                                return ret(idx, step, j);
                                            else
                                                continue;
                                        }
                                        else
                                        {
                                            continue;
                                        }
                                    }
                                }
                            }

                            bucket = bucket->next.get_address(my_pool_uuid);
                            step++;
                        } while (unlikely(bucket != nullptr));
                        return ret();
                    } //end while(true)
                      //        unlock(pop, lock);
                }

                size_type
                size()
                {
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid));
                    clht_hashtable_s *ht_ptr = m->ht.get_address(my_pool_uuid); //考虑是否需要增加meta
                    uint64_t n_buckets = ht_ptr->num_buckets;
                    bucket_s *bucket = nullptr;
                    size_type size = 0;

                    for (difference_type idx = 0; idx < n_buckets; idx++)
                    {
                        bucket = ht_ptr->table[idx].get_address(my_pool_uuid); //获得地址的为指针
                        do
                        {
                            for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                            {
                                if (bucket->slots[j] != nullptr)
                                    size++;
                            }

                            bucket = bucket->next.get_address(my_pool_uuid);
                        } while (unlikely(bucket != nullptr));
                    }

                    return size;
                }
#if 1
                size_type
                ht_status(bool is_increase, bool just_print)
                {
                    pool_base pop = get_pool_base();
                    if (try_lock(pop, &status_lock) && !is_increase)
                        return 0;

                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid)); //是否要拷贝操作
                    clht_hashtable_s *ht_ptr = m->ht.get_address(my_pool_uuid);
                    difference_type n_buckets = (difference_type)ht_ptr->num_buckets;
                    bucket_s *bucket = nullptr;
                    size_type size = 0;
                    int expands = 0;
                    int expands_max = 0;

                    for (difference_type idx = 0; idx < n_buckets; idx++)
                    {
                        bucket = &ht_ptr->table[idx];

                        int expands_cont = -1;
                        expands--;
                        do
                        {
                            expands_cont++;
                            expands++;
                            for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                            {
                                if (bucket->slots[j] != nullptr)
                                    size++;
                            }

                            bucket = bucket->next.get_address(my_pool_uuid);
                        } while (unlikely(bucket != nullptr));

                        if (expands_cont > expands_max)
                            expands_max = expands_cont;
                    }

                    double full_ratio = 100.0 * size / (n_buckets * ENTRIES_PER_BUCKET);

                    if (just_print)
                    {
                        printf("[STATUS-%02d] #bu: %7zu / #elems: %7zu / full%%: %8.4f%% / expands: %4d / max expands: %2d\n",
                               99, n_buckets, size, full_ratio, expands, expands_max);
                    }
                    else
                    {
                        if (full_ratio > 0 && full_ratio < CLHT_PERC_FULL_HALVE) //loadfactor<5%
                        {
                            ht_resize_pes(false /* is_increase */, (size_t)33); //调用ht_resize_pes函数
                        }
                        else if ((full_ratio > 0 && full_ratio > CLHT_PERC_FULL_DOUBLE) || expands_max > CLHT_MAX_EXPANSIONS || is_increase)
                        {
                            uint64_t inc_by = (uint64_t)(full_ratio / CLHT_OCCUP_AFTER_RES); //inc_by增长比例，后面需要变成2的n次方。
                            int inc_by_pow2 = pow2roundup(inc_by);

                            if (inc_by_pow2 == 1)
                            {
                                inc_by_pow2 = 2;
                            }
                            int ret = ht_resize_pes(true /* is_increase */,
                                                    (size_t)inc_by_pow2); //pes代表啥意思？
                            // return if crashed
                            if (ret == -1)
                                return 0;
                        }
                    }

                    unlock(pop, &status_lock);
                    return size;
                }
#endif
                //多线程协同扩容
                int ht_multithread_resize(bool is_increase, size_t by = 2)
                {
                    pool_base pop = get_pool_base();
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid));
                    m->ht_oldest = m->ht.get_address(my_pool_uuid);
                    size_t fixed_bucket_num = m->ht_oldest->num_buckets % resize_threads_num == 0 ? m->ht_oldest->num_buckets / resize_threads_num : m->ht_oldest->num_buckets / resize_threads_num + 1;

                    size_t num_buckets_new;
                    if (is_increase)
                    {
                        num_buckets_new = pow2roundup(by * m->ht_oldest->num_buckets);
                    }
                    persistent_ptr<clht_hashtable_s> ht_tmp;
                    transaction::run(pop, [&] {
                        // A transaction is required as the constructor of clht_hashtable_s
                        // invokes "make_persistent".
                        ht_tmp = make_persistent<clht_hashtable_s>(num_buckets_new); //以事务的方式进行临时的扩容的散列表构建！保证一致性。
                    });

                    clht_hashtable_s *ht_new = ht_tmp.get();
                    ht_new->version = m->ht_oldest->version + 1;

                    //多线程并发rehashing
                    for (size_type i = 0; i < resize_threads_num; i++)
                    {
                    }
                    if (m->is_resizing)
                    { //如果当前散列表正在扩容，那就多线程扩容
                        if (resize_bucket_num > 0)
                        { //表示当前扩容操作还未完成，只有resize_bucket_num为0时才表示扩容完毕
                            if (resize_bucket_num - fixed_bucket_num <= 0)
                            {
                                for (difference_type idx = 0;
                                     idx < (difference_type)resize_bucket_num; idx++)
                                {
                                    bucket_s *bu_cur = &m->ht_oldest->table[idx]; // oldest? bug
                                    bucket_cpy(bu_cur, ht_new);
                                }
                                ht_new->table_prev = m->ht;
                                pop.drain();

                                //switch to the new hash table
                                m->ht.off = ht_tmp.raw().off;
                                pop.persist(&m->ht.off, sizeof(clht_hashtable_ptr_t));
                                m->ht_oldest->table_new.off = ht_tmp.raw().off;
                                pop.persist(&m->ht_oldest->table_new.off, sizeof(clht_hashtable_ptr_t));
                                std::lock_guard<std::mutex> guard(resize_bucket_num_mutex);
                                resize_bucket_num = 0;
                                m->is_resizing = false;
                                pop.persist(&m->is_resizing, sizeof(bool));
                                return 1; //表示多线程扩容完毕
                            }
                            else
                            {
                                std::lock_guard<std::mutex> guard(resize_bucket_num_mutex);
                                resize_bucket_num = resize_bucket_num - fixed_bucket_num;
                                for (difference_type idx = resize_bucket_num; idx < resize_bucket_num + fixed_bucket_num; idx++)
                                {
                                    //idx < (difference_type)resize_bucket_num; idx++) // what's the logic operation should be here? bug
                                    {
                                        bucket_s *bu_cur = &m->ht_oldest->table[idx]; // oldest? bug
                                        bucket_cpy(bu_cur, ht_new);
                                    }
                                }
                            }
                        }
                    }
                }

                /// Round up to next higher power of 2 (return x if it's already a power
                /// of 2) for 32-bit numbers·
                static inline uint64_t
                pow2roundup(uint64_t x)
                {
                    if (x == 0)
                        return 1;
                    --x;
                    x |= x >> 1;
                    x |= x >> 2;
                    x |= x >> 4;
                    x |= x >> 8;
                    x |= x >> 16;
                    x |= x >> 32;
                    return x + 1;
                }
#if 1
                /**
     * Perform actual resizing. using multi-threaded collaborative concurrent resizing within a resize_lock.//lock-based multi-threaded concurrent resizing
     * 为了防止过度优化，关键是如何进行基于单lock的多线程并发扩容（是否可以实现---技术可行性方面）
    */
                int
                ht_resize_pes(bool is_increase, size_t by)
                {
                    pool_base pop = get_pool_base();
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid)); //静态类型转换并非是真正的拷贝操作。
                    clht_hashtable_s *ht_old = m->ht.get_address(my_pool_uuid);
                    if (try_lock(pop, &resize_lock))
                        return 0;

                    size_t num_buckets_new;
                    if (is_increase)
                    {
                        /* num_buckets_new = CLHT_RATIO_DOUBLE * ht_old->num_buckets; */
                        num_buckets_new = by * ht_old->num_buckets;
                    }
                    else
                    {
#if CLHT_HELP_RESIZE == 1
                        ht_old->is_helper = 0;
#endif
                        num_buckets_new = ht_old->num_buckets / CLHT_RATIO_HALVE; //这个是压缩表空间嘛？大小变为1/8！
                    }

                    persistent_ptr<clht_hashtable_s> ht_tmp;
                    transaction::run(pop, [&] {
                        // A transaction is required as the constructor of clht_hashtable_s
                        // invokes "make_persistent".
                        ht_tmp = make_persistent<clht_hashtable_s>(num_buckets_new); //以事务的方式进行临时的扩容的散列表构建！保证一致性。
                    });

                    clht_hashtable_s *ht_new = ht_tmp.get();
                    ht_new->version = ht_old->version + 1; //以版本化方式保证散列表更新的一致性。这里的ht_new和ht_old是否需要同meta进行联系。
/*
* 以下这部分是多线程并行扩容的关键部件！
*/
#if CLHT_HELP_RESIZE == 1
                    ht_old->table_tmp.off = ht_tmp.raw().off;
                    pop.persist(&ht_old->table_tmp.off, sizeof(clht_hashtable_ptr_t));

                    for (difference_type idx = 0;
                         idx < (difference_type)ht_old->num_buckets; idx++)
                    {
                        bucket_s *bu_cur = &ht_old->table[idx];
                        int ret = bucket_cpy(bu_cur, ht_new);
                        /* reached a point where the helper is handling */
                        if (ret == -1)
                            return -1;

                        if (!ret)
                            break;
                    }

                    if (is_increase && ht_old->is_helper != 1) /* there exist a helper */
                    {
                        while (ht_old->helper_done != 1)
                            atomic_backoff(); //阻塞以等待完成！
                    }
#else
                    for (difference_type idx = 0;
                         idx < (difference_type)ht_old->num_buckets; idx++)
                    {
                        bucket_s *bu_cur = &ht_old->table[idx];
                        int ret = bucket_cpy(bu_cur, ht_new);
                        if (ret == -1) //此处的返回值-1表示什么意思？
                            return -1;
                    }
#endif

                    ht_new->table_prev = m->ht;
                    int ht_resize_again = 0;
                    if (ht_new->num_expands >= ht_new->num_expands_threshold)
                    {
                        ht_resize_again = 1;
                    }

                    pop.drain();

                    // Switch to the new hash table
                    m->ht.off = ht_tmp.raw().off;
                    pop.persist(&m->ht.off, sizeof(clht_hashtable_ptr_t));
                    ht_old->table_new.off = ht_tmp.raw().off;
                    pop.persist(&ht_old->table_new.off, sizeof(clht_hashtable_ptr_t));

                    unlock(pop, &resize_lock);

                    if (ht_resize_again)
                        ht_status(true /* is_increase */, false /* just_print */);

                    return 1;
                }
#endif

                int
                bucket_cpy(bucket_s *bucket, clht_hashtable_s *ht_new)
                {
                    /*       if (!lock_acq_resize(&bucket->lock))//需要做适配修改或直接删除
            return 0;
       */

                    do
                    {
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                        {
                            if (bucket->slots[j] != nullptr)
                            {
                                hv_type hv = hasher{}(
                                    bucket->slots[j].get_address(my_pool_uuid)->first);
                                difference_type idx = static_cast<difference_type>(
                                    hv % static_cast<hv_type>(ht_new->num_buckets));
                                put_seq(ht_new, bucket->slots[j], idx);
                            }
                        }
                        bucket = bucket->next.get_address(my_pool_uuid);
                    } while (unlikely(bucket != nullptr));

                    return 1;
                }

                bool
                put_seq(clht_hashtable_s *hashtable, kv_ptr_t slot, difference_type idx)
                {
                    pool_base pop = get_pool_base();
                    //		clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid));
                    bucket_s *bucket = &hashtable->table[idx];

                    do
                    {
                        for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                        {
                            if (bucket->slots[j] == nullptr)
                            {
                                bucket->slots[j] = slot;
                                pop.persist(&bucket->slots[j].off, sizeof(kv_ptr_t));
                                return true;
                            }
                        }

                        if (bucket->next == NULL)
                        {
                            //            int null;
                            bucket_ptr_t b_new = clht_bucket_create_stats(
                                pop, hashtable, meta); //the third parameter can't be null，must be nullptr or 0
                            kv_ptr_t &s_new = b_new(my_pool_uuid)->slots[0];
                            s_new.off = slot.off;
                            pop.persist(&s_new.off, sizeof(kv_ptr_t));
                            return true;
                        }

                        bucket = bucket->next.get_address(my_pool_uuid);
                    } while (true);
                }

                void
                ht_resize_help(clht_hashtable_s *hashtable)
                {
                    if ((int32_t)__sync_fetch_and_sub(
                            (volatile uint32_t *)&hashtable->is_helper, 1) <= 0)
                        return;

                    for (difference_type idx = (difference_type)hashtable->hash;
                         idx >= 0; idx--)
                    {
                        bucket_s *bucket = &hashtable->table[idx];
                        if (!bucket_cpy(
                                bucket, hashtable->table_tmp.get_address(my_pool_uuid)))
                            break;
                    }

                    hashtable->helper_done = 1;
                }

                void
                print()
                {
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid));
                    clht_hashtable_s *hashtable = m->ht.get_address(my_pool_uuid); //需要做适配修改，联系上meta
                    difference_type n_buckets = (difference_type)hashtable->num_buckets;
                    std::cout << "Number of buckets: " << n_buckets << std::endl;

                    for (difference_type idx = 0; idx < n_buckets; idx++)
                    {
                        bucket_s *bucket = &hashtable->table[idx];
                        std::cout << "[[" << idx << "]]";

                        do
                        {
                            for (size_t j = 0; j < ENTRIES_PER_BUCKET; j++)
                            {
                                if (bucket->slots[j] != nullptr)
                                {
                                    value_type *e =
                                        bucket->slots[j].get_address(my_pool_uuid);
                                    std::cout << "(" << e->first
                                              << "/" << e.second << ")-> ";
                                }
                            }

                            bucket = bucket->next.get_address(my_pool_uuid);
                            std::cout << " ** -> ";
                        } while (unlikely(bucket != nullptr));
                        std::cout << std::endl;
                    }

                    fflush(stdout);
                }

                uint64_t
                capacity()
                {
                    clht_meta *m = static_cast<clht_meta *>(meta(my_pool_uuid));
                    clht_hashtable_s *hashtable = m->ht.get_address(my_pool_uuid); //需要做适配修改
                    difference_type n_buckets = (difference_type)hashtable->num_buckets;

                    uint64_t num = 0;
                    for (difference_type idx = 0; idx < n_buckets; idx++)
                    {
                        bucket_s *bucket = &hashtable->table[idx];
                        do
                        {
                            num++; //bucket num
                            bucket = bucket->next.get_address(my_pool_uuid);
                        } while (unlikely(bucket != nullptr));
                    }

                    return num * ENTRIES_PER_BUCKET;
                }

                clht_meta_ptr_t meta;
                unsigned thread_num;
                //	p<uint64_t> resize_bucket_num;//自己增加的，初始值为最旧表的总bucket数，为0时表示多线程协同扩容完成，每个扩容线程每次取固定数量的bucket进行扩容，多个扩容线程可以同时进行扩容操作。
                p<size_type> resize_threads_num = 2; //默认扩容线程数为2，可动态调整

                p<size_type> work_threads_num; //指的是work_thread_num
                p<std::atomic<bool>> run_expand_thread;
                //    clht_hashtable_ptr_t ht;
                //    uint8_t next_cache_line[CACHE_LINE_SIZE - (sizeof(clht_hashtable_ptr_t))];
                //    clht_hashtable_ptr_t ht_oldest;
                //    ht_ts_ptr_t version_list;
                //    size_t version_min;
                persistent_ptr<persistent_ptr<clht_meta>[]> tmp_meta;
                persistent_ptr<persistent_ptr<value_type>[]> tmp_entry;

                std::vector<std::thread> resize_threads;
                clht_lock_t resize_lock;
                //    clht_lock_t gc_lock;
                clht_lock_t status_lock;

                /** ID of persistent memory pool where hash map resides. */
                p<uint64_t> my_pool_uuid;

#ifdef LFCLHT_DEBUG
                std::vector<std::fstream> thread_logs;
#endif
            };

        } /* namespace experimental */
    }     /* namespace obj */
} /* namespace pmem */

#endif /* PMEMOBJ_CLHT_HPP */
