//https://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html

/*
__ATOMIC_RELAXED
Implies no inter-thread ordering constraints.

__ATOMIC_CONSUME
This is currently implemented using the stronger __ATOMIC_ACQUIRE memory order because of a deficiency in C++11’s semantics for memory_order_consume.

__ATOMIC_ACQUIRE
Creates an inter-thread happens-before constraint from the release (or stronger) semantic store to this acquire load. Can prevent hoisting of code to before the operation.

__ATOMIC_RELEASE
Creates an inter-thread happens-before constraint to acquire (or stronger) semantic loads that read from this release store. Can prevent sinking of code to after the operation.

__ATOMIC_ACQ_REL
Combines the effects of both __ATOMIC_ACQUIRE and __ATOMIC_RELEASE.

__ATOMIC_SEQ_CST
Enforces total ordering with all other __ATOMIC_SEQ_CST operations.
*/

#define ATOMIC_LOAD(ptr) __atomic_load_n(ptr, __ATOMIC_ACQUIRE)
#define ATOMIC_STORE(ptr) __atomic__store_n(ptr, __ATOMIC_RELEASE)

// algorithm operation

// FAA:fetch and add
#define FAA(ptr, val) __atomic_fetch_add(ptr, val, __ATOMIC_ACQ_REL)
#define AAF(ptr, val) __atomic_add_fetch(ptr, val, __ATOMIC_ACQ_REL)

#define PREFETCH(x) __builtin_prefetch(x)
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

#define CACHELINESIZE (64)
#define ____CACHELINE_ALIGNED __attribute__((aligned(CACHELINESIZE)))


/*

/*
 * 如果*p==*u的话 *p=v
 * 如果*p!=*u的话 *u=*p
 * false:强一致还是弱一致
 * 后面两个分别是成功时的内存序和失败后的内存序
 *
 * 内存序参考
 * https://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html
 *
 * weak(弱一致性)在有的平台上（ARM，Itanium, PowerPC等）会存在失败的可能性。
 * 即当*ptr == *expected依然有可能什么都不做而返回false。
 * 在x86平台来说，这两者可以说是没什么区别。
 * 那么采用compare_exchange_weak并且使用{循环}来判断
 * 性能会比单次的strong(强一致性)更好，移植性也更好
 */
#define CAS(_p, _u, _v)                                              \
    (__atomic_compare_exchange_n(_p, _u, _v, TRUE, __ATOMIC_ACQ_REL, \
                                 __ATOMIC_RELAXED))

/**
 * 获取lock（加锁）
 * @param bucket 要加锁的bucket
 * @param index 桶的索引位置
 */
inline void get_lock(int *flag)
{
    uint64_t old_value = 0;
    uint64_t new_value = 0;
    do
    {
        while (1)
        {
            old_value = ATOMIC_LOAD(flag);
            if (!old_value)
            { // 0代表获得锁，跳出获取loop循环
                break;
            }
        }
        new_value = 1;
    } while (!CAS(flag, &old_value, new_value));
}

/**
 * 释放锁 （本函数不检测是否已经成功对bucket加锁）
 * @param bucket
 * @required bucket已经加锁
 */
inline void release_lock(int *flag)
{
    ATOMIC_STORE(flag, 0);
    // printf("flag: *p %p: %d\n", flag, *flag);
}
/* 
struct cas_spin_lock
{
    uint64_t *lock;

    cas_spin_lock() = delete;
    cas_spin_lock(cas_spin_lock &other) = delete;
    cas_spin_lock(cas_spin_lock &&other) = delete;

    cas_spin_lock(uint64_t *lk)
    {
        lock = lk;
        get_lock(lock);
    }

    ~cas_spin_lock()
    {
        release_lock(lock);
    }
};
 */
struct cas_spin_lock
{
    int &lock;

    cas_spin_lock() = delete;
    cas_spin_lock(cas_spin_lock &other) = delete;
    cas_spin_lock(cas_spin_lock &&other) = delete;

    cas_spin_lock(int &lk) : lock(lk)
    {
        // lock = lk;
        get_lock(&lock);
    }

    ~cas_spin_lock()
    {
        release_lock(&lock);
    }
};


