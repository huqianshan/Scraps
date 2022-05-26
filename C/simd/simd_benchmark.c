
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <immintrin.h>
#include <libpmem.h>

#include "../intel_tsc/tsc.h"

#define true (1)
#define false (0)
#define BITS (8)

#define BUCKET_SIZE_BITS (512)
#define BUCKET_SIZE_BYTES (BUCKET_SIZE_BITS / BITS)
// #define FINGER_BASE (255)

#define ALLOC_ALIGN (64)
//判断var在pos处的数据是否为1 是的话 返回1 否的话返回0
#define CHECK_BIT(var, pos) ((((var) & ((uint64_t)1 << pos)) > 0) ? (1) : (0))

uint64_t N = 1;
uint64_t FINGER_BASE = 255;
const uint64_t BUF_LEN = 1024ull * 1024 * 1024 * 10;
const char *persist_file = "/data/pmem0/simd_benchmark";

typedef struct Area512
{
    uint8_t finger[BUCKET_SIZE_BYTES];
} BUCKET, *BUCKET_PTR;

uint32_t find(uint8_t *src, uint8_t key, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (src[i] == key)
        {
            return i;
        }
    }
    return -1;
}

uint32_t find128(uint8_t *src, uint8_t key)
{
    const __m128i key_data = _mm_set1_epi8(key);
    __m128i seg_data = _mm_loadu_si128((__m128i *)(src));
    __m128i rv_mask = _mm_cmpeq_epi8(seg_data, key_data);
    uint32_t mask = _mm_movemask_epi8(rv_mask);
    return __builtin_ffs(mask) - 1;
}

uint32_t find256(uint8_t *src, uint8_t key)
{
    const __m256i key_data = _mm256_set1_epi8(key);
    __m256i seg_data = _mm256_loadu_si256((__m256i *)(src));
    __m256i rv_mask = _mm256_cmpeq_epi8(seg_data, key_data);
    uint32_t mask = _mm256_movemask_epi8(rv_mask);
    //返回右起第一个‘1’的位置。 0:-1
    return __builtin_ffs(mask) - 1;
}

uint32_t find256avx(uint8_t *src, uint8_t key)
{
    const __m256i key_data = _mm256_set1_epi8(key);
    __m256i seg_data = _mm256_loadu_si256((__m256i *)(src));
    __mmask32 mask = _mm256_cmpeq_epi8_mask(seg_data, key_data);
    //返回右起第一个‘1’的位置。 0:-1
    return __builtin_ffs(mask) - 1;
}

uint32_t find512(uint8_t *src, uint8_t key)
{
    const __m512i key_data = _mm512_set1_epi8(key);
    __m512i seg_data = _mm512_loadu_si512((__m512i *)(src));
    __mmask64 mask = _mm512_cmpeq_epu8_mask(seg_data, key_data);
    //返回右起第一个‘1’的位置。 0:-1
    return __builtin_ffsll(mask) - 1;
}

uint32_t bucket_find(BUCKET *src, uint8_t key)
{
    return find(src->finger, key, BUCKET_SIZE_BYTES);
}

uint32_t bucket_find_128bit(BUCKET *src, uint8_t key)
{
    uint32_t cur_len = 128;
    uint32_t ret = 0;

    uint8_t loop = BUCKET_SIZE_BITS / cur_len;
    uint8_t *base = src->finger;

    for (uint8_t i = 0; i < loop; i++)
    {
        ret = find128(base + i * (cur_len / BITS), key);
        if (ret != -1)
        {
            return ret;
        }
    }
    return ret;
}

uint32_t bucket_find_256bit(BUCKET *src, uint8_t key)
{
    uint32_t cur_len = 256;
    uint32_t ret = 0;

    uint8_t loop = BUCKET_SIZE_BITS / cur_len;
    uint8_t *base = src->finger;

    for (uint8_t i = 0; i < loop; i++)
    {
        ret = find256(base + i * (cur_len / BITS), key);
        if (ret != -1)
        {
            return ret;
        }
    }
    return ret;
}

uint32_t bucket_find_256bit_avx(BUCKET *src, uint8_t key)
{
    uint32_t cur_len = 256;
    uint32_t ret = 0;

    uint8_t loop = BUCKET_SIZE_BITS / cur_len;
    uint8_t *base = src->finger;

    for (uint8_t i = 0; i < loop; i++)
    {
        ret = find256avx(base + i * (cur_len / BITS), key);
        if (ret != -1)
        {
            return ret;
        }
    }
    return ret;
}

// #define uint32_t (*func)(BUCKET *, uint8_t) FUNC_PTR

uint32_t bucket_find_512bit(BUCKET *src, uint8_t key)
{
    uint32_t cur_len = 512;
    uint32_t ret = 0;

    uint8_t loop = BUCKET_SIZE_BITS / cur_len;
    uint8_t *base = src->finger;

    for (uint8_t i = 0; i < loop; i++)
    {
        ret = find512(base + i * (cur_len / BITS), key);
        if (ret != -1)
        {
            return ret;
        }
    }
    return ret;
}

BUCKET_PTR create_volatile_table(uint64_t size)
{
    srand(321);
    BUCKET_PTR table = (BUCKET_PTR)aligned_alloc(ALLOC_ALIGN, size * sizeof(BUCKET));
    for (uint64_t i = 0; i < size; i++)
    {
        uint8_t *src = table[i].finger;
        for (uint8_t k = 0; k < BUCKET_SIZE_BYTES; k++)
        {

            src[k] = (rand() % FINGER_BASE);

            /*   printf("%3d ", (uint32_t)src[k]);
            if ((k + 1) % 32 == 0)
            {
                printf("\n");
            } */
        }
    }
    return table;
}

BUCKET_PTR create_persist_table(uint64_t size, size_t *mapped_len)
{
    srand(321);
    char *pmemaddr;
    int is_pmem;
    BUCKET_PTR table;

    /* create a pmem file and memory map it */
    if ((pmemaddr = pmem_map_file(persist_file, BUF_LEN,
                                  PMEM_FILE_CREATE,
                                  0666, mapped_len, &is_pmem)) == NULL)
    {
        perror("pmem_map_file");
        exit(1);
    }

    table = (BUCKET_PTR)pmemaddr;
    // (BUCKET_PTR)aligned_alloc(ALLOC_ALIGN, size * sizeof(BUCKET));
    for (uint64_t i = 0; i < size; i++)
    {
        uint8_t *src = table[i].finger;
        for (uint8_t k = 0; k < BUCKET_SIZE_BYTES; k++)
        {

            src[k] = (rand() % FINGER_BASE);

            /*   printf("%3d ", (uint32_t)src[k]);
            if ((k + 1) % 32 == 0)
            {
                printf("\n");
            } */
        }
    }
    pmem_flush(table, size * sizeof(BUCKET));
    return table;
}

void bench(BUCKET *table, uint64_t size, uint32_t (*func)(BUCKET *, uint8_t))
{
    srand(123);
    uint64_t overhead = measure_tsc_overhead();
    uint64_t begin = bench_start();

    uint32_t ret = 0;
    uint8_t key = 0;
    BUCKET_PTR bkt = table;
    uint64_t find_miss = 0;
    for (uint64_t i = 0; i < size; i++)
    {

        bkt = table + rand() % size;
        for (uint64_t j = 0; j < N; j++)
        {
            key = rand() % FINGER_BASE;
            // ret = bucket_find(bkt, key);
            // ret = bucket_find_128bit(bkt, key);
            // ret = bucket_find_256bit(bkt, key);
            // ret = bucket_find_512bit(bkt, key);
            ret = (*func)(bkt, key);
            // printf("%16p find key: %2d in pos: %u \n", bkt, key, ret);
            if (ret == UINT32_MAX)
            {
                find_miss++;
                // exit(EXIT_FAILURE);
            }
        }
    }
    uint64_t end = bench_end();

    uint64_t duration = cycles_to_ns(end - begin - overhead);
    uint64_t times = size * N;
    /*  printf("find: %12lu buckets, repeat: %4lu total %12lu times find miss %lu ; cost time: %12lu ns; avg: %3.4lf ns/op\n",
           size, N, times, find_miss, duration, duration * 1.0 / times); */
    printf("%14lu,%2lu,%4lu,%14lu,%12lu,%12lu,%10.4lf\n",
           size, N, FINGER_BASE, times, find_miss, duration, duration * 1.0 / times);
}

int main(int argc, char const *argv[])
{

    uint64_t size = 16;
    if (argc > 1)
    {
        size = atoll(argv[1]) * 1024 * 1024;
        N = atoll(argv[2]);
        FINGER_BASE = atoll(argv[3]);
    }

    size_t mapped_len = 0;
    BUCKET_PTR table = create_persist_table(size, &mapped_len);

    printf("%16s,%14s,%2s,%4s,%14s,%12s,%12s,%10s\n", "Name", "Buckets", "N", "BASE", "Total", "Miss", "Times/ns", "Avg op/ns");

    printf("[%14s],", "bucket_find");
    bench(table, size, &bucket_find);

    printf("[%14s],", "bucket_find128");
    bench(table, size, &bucket_find_128bit);

    printf("[%14s],", "bucket_find256");
    bench(table, size, &bucket_find_256bit);

    printf("[%14s],", "bucket_f256avx");
    bench(table, size, &bucket_find_256bit_avx);

    printf("[%14s],", "bucket_find512");
    bench(table, size, &bucket_find_512bit);

    // free(table);
    pmem_unmap(table, mapped_len);
    return 0;
}
