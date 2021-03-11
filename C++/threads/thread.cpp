#include <iostream>
#include <bitset>
#include <mutex>
#include <thread>
#include <vector>

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

int main(int argc, char **argv)
{
    int buckets = 2;
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

    delete td;
}
