#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
//https://gcc.gnu.org/onlinedocs/gcc/_005f_005fatomic-Builtins.html
#define NUMTHREADS (16)
#define ATOMIC_LOAD(ptr) __atomic_load_n(ptr, __ATOMIC_ACQUIRE)
#define ATOMIC_STORE(ptr) __atomic__store_n(ptr, __ATOMIC_RELEASE)
#define CAS(_p, _u, _v)                                              \
    (__atomic_compare_exchange_n(_p, _u, _v, TRUE, __ATOMIC_ACQ_REL, \
                                 __ATOMIC_RELAXED))

// FAA:fetch and add
#define FAA(ptr, val) __atomic_fetch_add(ptr, val, __ATOMIC_ACQ_REL)

typedef pthread_mutex_t Lock;
typedef pthread_cond_t Cond;

static inline int lock(Lock *lk)
{
    return pthread_mutex_lock(lk);
}

static inline int unlock(Lock *lk)
{
    return pthread_mutex_unlock(lk);
}

static inline int cond_wait(Cond *cond, Lock *lk)
{
    // lock(lk);
    return pthread_cond_wait(cond, lk);
    // unlock(lk);
}

static inline int notify(Cond *cond)
{
    return pthread_cond_signal(cond);
}

static inline int notify_all(Cond *cond)
{
    return pthread_cond_broadcast(cond);
}

Lock resize_mutex = PTHREAD_MUTEX_INITIALIZER;
Cond resize_cond = PTHREAD_COND_INITIALIZER;
int resize_flag = 0;

Lock flag_mutex = PTHREAD_MUTEX_INITIALIZER;
Cond flag_cond = PTHREAD_COND_INITIALIZER;
int create_flag = 0;

void *ThreadEntry(void *id)
{

    const int myid = (long)id; // force the pointer to be a 64bit integer
    printf("[thread %d] Create Success.. \n", myid);
    // wait Resize Cond Flag
    lock(&resize_mutex);
    create_flag++;
    // printf("[thread %d] Try to test Condivariable.. \n", myid);
    cond_wait(&resize_cond, &resize_mutex);
    // printf("[thread %d] Get wake up.. \n", myid);
    unlock(&resize_mutex);

    const int workloops = 2;
    for (int i = 0; i < workloops; i++)
    {
        printf("[thread %d] working (%d/%d)\n", myid, i, workloops - 1);
        sleep(1); // simulate doing some costly work
    }

    // lock(&flag_mutex);

    // resize_flag++;
    int tem = FAA(&resize_flag, 1);
    printf("[thread %d] Done Reize~ Adding resize flag:%d.\n", myid, tem);
    // pthread_cond_signal(&flag_cond);
    // unlock(&flag_mutex);
    printf("[thread %d] Exit.. \n", myid);
    return NULL;
}

void create_thread(pthread_t *threads)
{

    for (int t = 0; t < NUMTHREADS; t++)
    {
        pthread_create(&threads[t], NULL, ThreadEntry, (void *)(long)t);
    }
    // create_flag = 1;
}

int main(int argc, char **argv)
{

    printf("[thread main] starting\n");

    pthread_t threads[NUMTHREADS];
    create_thread(threads);

    while (create_flag != NUMTHREADS)
    {
        // printf("[thread main] %d\n", create_flag);
    }

    printf("[thread main] begin resize %d\n", create_flag);
    //1. begin resize
    lock(&resize_mutex);
    notify_all(&resize_cond);
    // for (int i = 0; i < NUMTHREADS; i++)
    // {
    //     pthread_cond_signal(&resize_cond);
    // }
    unlock(&resize_mutex);

    // lock(&flag_mutex);
    // printf("[thread main] resize_flag is %d which is < %d so waiting on cond\n",
    //        resize_flag, (int)NUMTHREADS);
    // while (resize_flag < NUMTHREADS)
    // {
    //     cond_wait(&flag_cond, &flag_mutex);

    //     printf("[thread main] wake - cond was signalled.Current Resize_Flag %d\n", resize_flag);
    // }
    // unlock(&flag_mutex);

    while (ATOMIC_LOAD(&resize_flag) < NUMTHREADS)
    {
        // printf("[]");
        // pause();
    }
    printf("[thread main] %d\n", resize_flag);

    return 0;
}