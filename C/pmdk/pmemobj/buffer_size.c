
#include <inttypes.h>
#include <libpmem.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h> // 增加时间统计头文件

#define LAYOUT_NAME "buffer_size" /* will use this in create and open */
#define LAYOUT_PATH "/data/pmem0/oh-your-god"
#define LAYOUT_SIZE (32ul * 1024ul * 1024ul * 1024ul)

#define MAX_ALLOC_SIZE (31ul * 1024ul * 1024ul * 1024ul)
#define MAX_ARRAY_LEN (MAX_ALLOC_SIZE / MAX_BUF_LEN)

#define MAX_BUF_LEN (4096) /* maximum length of our buffer */
#define THREAD_MAX_NUM (16)

#define CACHELINE_SIZE (64)
#define ALIGNED(N) __attribute__((aligned(N)))

struct my_root
{
    int i;
};

typedef struct node
{
    char buf[MAX_BUF_LEN];
} Node, *NodePtr;

typedef struct ALIGNED(CACHELINE_SIZE) input
{
    NodePtr addr;
    int tid;
    uint64_t begin;
    uint64_t end;
} input;

typedef struct tid_stat
{
    uint64_t cost_time;
    uint64_t access_num;
    uint64_t latency;
    double iops;
} tid_stat;

tid_stat thrds_stats[72];
char dest[72][MAX_BUF_LEN];
uint64_t time_array[72];

void *do_memcpy(void *in)
{
    input *it = (input *)in;

    Node *addr = it->addr;
    int tid = it->tid;
    uint64_t begin = it->begin;
    uint64_t end = it->end;
    // printf(" %" PRIu64 " %" PRIu64 " %d \n", begin, end, tid);

    uint64_t main_timeuse = 0;
    uint64_t access_num = 0;

    NodePtr base_ptr = addr; //bug here
    Node *cur_ptr = addr + begin;

    struct timeval ts, te;
    // 随机访问： 跨过两个cacheline
    int occupied_cacheline = 64 * CACHELINE_SIZE / sizeof(Node) + 1;
    occupied_cacheline = (occupied_cacheline <= 1) ? 2 : occupied_cacheline;
    // occupied_cacheline = 1;
    // printf("Thtreads[%d] occupied_cacheline:%d\n", it->tid, occupied_cacheline);

    char new_buf[MAX_BUF_LEN];
    gettimeofday(&ts, NULL);
    for (uint64_t i = begin; i < end; i += occupied_cacheline)
    {

        cur_ptr = base_ptr + i;
        access_num++;
        // memset(cur_ptr, 0xFFFFFFFF, MAX_BUF_LEN);
        memcpy(new_buf, cur_ptr->buf, MAX_BUF_LEN);
    }
    gettimeofday(&te, NULL);

    main_timeuse = 1000000 * (te.tv_sec - ts.tv_sec) +
                   te.tv_usec - ts.tv_usec;
    time_array[tid] = main_timeuse;
    printf("\n/ #cost_time %8" PRIu64 "us / #Access_items %8" PRIu64 "/ # IOPS %8.4lfMIOPS / #avg_latency %8.4lfns\n",
           main_timeuse, access_num, access_num * 1.0 / main_timeuse, main_timeuse * 1000.0 / access_num);

    thrds_stats[tid].cost_time = main_timeuse;
    thrds_stats[tid].access_num = access_num;
    thrds_stats[tid].iops = access_num * 1.0 / main_timeuse;
    thrds_stats[tid].latency = main_timeuse * 1000 / access_num;
    return NULL;
}

int main(int argc, char *argv[])
{

    /*---------------------------Pmem library-------------------------------------*/
    char *paddr;
    size_t mapped_len;
    int is_pmem;
    if ((paddr = pmem_map_file(LAYOUT_PATH, LAYOUT_SIZE, PMEM_FILE_CREATE,
                               0666, &mapped_len, &is_pmem)) == NULL)
    {
        perror("failed to create pool\n");
        return -1;
    }
    // printf("map size %zuGB,%zu\n", mapped_len / 1024 / 1024 / 1024, mapped_len);

    NodePtr nptr = (NodePtr)paddr;
    int occupied_cacheline = 32 * CACHELINE_SIZE / sizeof(Node) + 1;
    occupied_cacheline = (occupied_cacheline <= 1) ? 2 : occupied_cacheline;
    printf("/ #BucketSize: %4d/%zu Bytes / occupied_cacheline:%1d / #BucketLength:%8zu / #TableSize:%8zu MB",
           MAX_BUF_LEN, sizeof(Node), occupied_cacheline, MAX_ARRAY_LEN, MAX_BUF_LEN * MAX_ARRAY_LEN / 1024 / 1024);

    /*----------------------Write Bukcet Preparation------------------------------------*/
    // // char buffer[10240];
    // NodePtr cur_ptr;
    // for (size_t i = 0; i < MAX_ARRAY_LEN; i++)
    // {
    //     cur_ptr = (NodePtr)(nptr + i);
    //     if ((uint64_t)cur_ptr == 0x7fffc0000000)
    //     {
    //         printf("%p %p\n", cur_ptr, cur_ptr->buf);
    //     }
    //     // sprintf(buffer,"Test%zu",i);
    //     // memset(cur_ptr->buf, 0xFFFFFFFF, MAX_BUF_LEN);
    //     // memcpy(cur_ptr->buf,buffer,)
    // }

    // create pthreads array for test
    int thread_num = THREAD_MAX_NUM;
    pthread_t pt[thread_num];
    input inputs[thread_num];

    // do memory test
    for (int i = 0; i < thread_num; i++)
    {
        inputs[i].addr = nptr;
        inputs[i].tid = i;
        inputs[i].begin = (i) * (MAX_ARRAY_LEN / thread_num);
        inputs[i].end = (i + 1) * (MAX_ARRAY_LEN / thread_num);
        pthread_create(&pt[i], NULL, do_memcpy, (void *)&inputs[i]);
    }

    uint64_t max_cost_time = 0;
    uint64_t total_cost_time = 0;
    uint64_t avg_cost_time = 0;

    uint64_t total_ops = 0;
    for (int i = 0; i < thread_num; i++)
    {
        pthread_join(pt[i], NULL);
        // printf("Thread[%2d] timeuse:%8" PRIu64 "us\n", i, time_array[i]);
        max_cost_time = (time_array[i] > max_cost_time) ? (time_array[i]) : max_cost_time;
        total_cost_time += time_array[i];
        total_ops += thrds_stats[i].access_num;
    }
    avg_cost_time = total_cost_time / thread_num;

    // print test results
    printf("/ #Threads: %d / #Time: %10" PRIu64 " / #IOPS: %8.4lfMops/s / #Bandwidth: %8.4lfGB/s\n",
           thread_num, avg_cost_time, (total_ops * 1.0) / avg_cost_time, (total_ops * sizeof(Node) * 1.0) / (avg_cost_time * 1024));

    pmem_unmap(paddr, LAYOUT_SIZE);
}
