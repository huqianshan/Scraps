#include <iostream>
#include <bitset>
#include <mutex>
#include <thread>
#include <vector>
#include <cassert>
#include <atomic>
#include <string>

using namespace std;

/**
 * The builtin performs an atomic compare and swap. That is, if the
 * current value of *ptr is oldval, then write newval into *ptr.
 * Return true if the comparison is successful and newval was written.
 */
#define CAS(ptr, oldval, newval) \
    (__sync_bool_compare_and_swap(ptr, oldval, newval))

#define FAX(ptr, value) (__sync_fetch_and_xor(ptr, value))
#define XAF(ptr, value) (__sync_xor_and_fetch(ptr, value))
// #define POPCOUNTUL(n) (__builtin__popcountll(n))
// #define POPCOUNTUL(n) (_mm_popcnt_u64(n))
int popcount(uint64_t n)
{
#ifdef _MSC_VER // Intel style assembly
    __asm popcnt rax, n;
#elif __GNUC__ // AT&T style assembly
    __asm__("popcnt %0,%%rax" ::"r"(n));
#else
#error "other POPCNT implementations go here"
#endif
}

// bool __sync_val_compare_and_swap (type *ptr, type oldval, type newval)
/*
These builtins perform an atomic compare and swap. That is, if the current
value of *ptr is oldval, then write newval into *ptr. The “bool” version
returns true if the comparison is successful and newval was written.

NOTE: oldval will NOT be updated if the atomic operation fails.
*/
/* #define CAS(ptr, oldval, newval) \
    (__sync_val_compare_and_swap(ptr, oldval, newval)) */

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

typedef struct thread_input
{
    int begin;
    int end;
    int tid;
    bool flag;

    thread_input(int b, int e, int d, bool f)
        : begin(b), end(e), tid(d), flag(f)
    {
    }
    thread_input()
    {
        begin = 0;
        end = 0;
        tid = 0;
        flag = false;
    }
} thread_input;

typedef struct thread_resize
{
    vector<thread_input> thrds;
    vector<thread> vecOfthreads;
    // mutex mut;
    uint64_t flag;

    thread_resize(int buckets, int thread_num)
    {
        thrds.resize(thread_num); //bug may be new dynamic allocate
        flag = 0;
        // thread_num maygreater than buckets
        int fix_num = (buckets > thread_num) ? buckets / thread_num : 1;
        for (int i = 0; i < thread_num && (i + 1) * fix_num <= buckets;
             i++)
        {
            thrds[i].begin = i * fix_num;
            thrds[i].end = (i + 1) * fix_num;
            thrds[i].tid = i;
        }
        int remain = buckets - thread_num * fix_num;
        thrds[thread_num - 1].end += (remain < 0) ? 0 : remain;
    }

    void
    print()
    {
        int thread_num = thrds.size();
        for (int i = 0; i < thread_num; i++)
        {
            cout << thrds[i].begin << " " << thrds[i].end << " "
                 << thrds[i].tid << " " << endl;
        }
    }

    void
    worker(int tid)
    {
        /*         int begin = thrds[tid].begin;
        int end = thrds[tid].end; */
        //lock_guard<mutex> lck(mut);
        /*         cout << "threads" << thrds[tid].tid
             << "  begin: " << this_thread::get_id() << endl;
        for (int i = begin; i < end; i++)
        {
            cout << i << " ";
        } */
        // set tid bit is 1
        uint64_t shift = 1ULL << tid;
        bitset<sizeof(uint64_t) * 8> raw_flag(FAX(&flag, shift));
        bitset<sizeof(uint64_t) * 8> new_flag(flag);
        /*         cout << endl
             << "shift:" << shift << "raw_flag:" << raw_flag
             << "new flag" << new_flag << endl; */
        /*         cout << endl
             << "threads" << thrds[tid].tid << " end: " << endl; */
    }

    void
    run()
    {
        int thread_num = thrds.size();

        for (int i = 0; i < thread_num; i++)
        {
            thread tem(&thread_resize::worker, this, i);
            vecOfthreads.push_back(std::move(tem));
        }
    }
    void
    wait()
    {
        for (auto &th : vecOfthreads)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
    }
    ~thread_resize()
    {
        wait();
        flag = 0;
    }
} thread_resize;

// for atomic operations
int x = 0;
int y = 0;
void t1()
{
    y = 20;
    x = 10;
}

void t2()
{

    if (x == 10)
    {
        assert(y == 20);
    }
}

std::atomic<int> cnt = {0};

void f()
{
    for (int n = 0; n < 1000; ++n)
    {
        cnt.fetch_add(1, std::memory_order_relaxed);
    }
}

std::atomic<std::string *> ptr;
int data;

void producer()
{
    std::string *p = new std::string("Hello");
    data = 42;
    ptr.store(p, std::memory_order_release);
}

void consumer()
{
    std::string *p2;
    while (!(p2 = ptr.load(std::memory_order_acquire)))
        ;
    assert(*p2 == "Hell1o"); // never fires
    assert(data == 42);      // never fires
}
int main(int argc, char **argv)
{
    /*     int buckets = 2;
    int thread_num = 2;

    thread_resize *td = new thread_resize(buckets, thread_num);
    // td->print();
    cout << td->flag << endl;
    td->run();
    uint64_t test = 1ULL;
    test = ~test + 1;

    while (popcount(td->flag) != thread_num)
    {
        // cout << "..." << endl;
    }
    cout << td->flag << endl
         << popcount(td->flag) << endl;

    delete td; */

    /*     while (true)
    {
        thread tid_a(t1);
        thread tid_b(t2);
        cout << tid_a.get_id() << endl;
        cout << tid_b.get_id() << endl;
        y = 1;
        x = 9;
        tid_a.join();
        tid_b.join();

    } */
    /*     std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n)
    {
        v.emplace_back(f);
    }
    for (auto &t : v)
    {
        t.join();
    }
    std::cout << "Final counter value is " << cnt << '\n'; */
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}
