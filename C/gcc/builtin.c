
#include <immintrin.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

#!/bin/bash
rm -f /data/pmem0/vecsearch1/*
make clean
make
sudo perf record -g -F 10000 ./demo --nodes 100000 --test_count 200000 --populate true
sudo perf record -g -F 10000 ./demo --nodes 100000 --test_count 200000 --populate false
sudo perf report -n --stdio >call_function.txt

sudo perf script -i perf.data &>perf.unfold

/home/hjl/download/FlameGraph/stackcollapse-perf.pl perf.unfold &>perf.folded

sudo /home/hjl/download/FlameGraph/flamegraph.pl perf.folded >perf.svg

*/
/*
— Built-in Function: int __builtin_ffs (unsigned int x)

Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
返回右起第一个‘1’的位置。

— Built-in Function: int __builtin_clz (unsigned int x)

Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
返回左起第一个‘1’之前0的个数。

— Built-in Function: int __builtin_ctz (unsigned int x)

Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
返回右起第一个‘1’之后的0的个数。

— Built-in Function: int __builtin_popcount (unsigned int x)

Returns the number of 1-bits in x.
返回‘1’的个数。
*/

static inline int find_last_set_64(uint64_t val)
{
    return 64 - __builtin_clzll(val) - 1;
}

// -------- 点乘 dot multly 加速--------------//
#define N (6400000)
#define ALIGNED_BYTES (8)
/**
 * 
 * dot 基础实现版本
 * 
**/
float dot_raw(const float *x, const float *y, int f)
{
    float s = 0;
    for (int z = 0; z < f; z++)
    {
        s += (*x) * (*y);
        x++;
        y++;
    }
    return s;
}

/**
 * 
 * dot _mm256_dp_ps  float版本
 * 
**/

float dot_mm256(const float *x, const float *y, int len)
{

    float inner_prod = 0.0f;
    __m256 X, Y;                      //Declare two variables stored in the 128-bit special register of SSE
    __m256 acc = _mm256_setzero_ps(); // Declare a variable stored in a 128-bit special register in SSE to store the result of X+Y, the initial value is 0
    float temp[8];                    //Store the parameters of the intermediate variables

    long i;
    for (i = 0; i + 8 < len; i += 8)
    {                                                  //128-bit special register, which can handle 4 groups of 32-bit variable operations at one time
        X = _mm256_loadu_ps(x + i);                    // Load x to X (because 128 bits can store four 32-bit data, the default is to load 4 consecutive parameters at a time)
        Y = _mm256_loadu_ps(y + i);                    //Same as above
        acc = _mm256_add_ps(acc, _mm256_mul_ps(X, Y)); //x*y, the sum of x1*y1 in each round, the sum of x2*y2, the sum of x3*y3, the sum of x4*y4, and the final result The four sums are placed in the 128-bit register of acc.
    }
    _mm256_storeu_ps(&temp[0], acc); // Load 4 32-bit data in acc into memory
    //dot multiplication sum
    long j;
    for (j = 0; j < 8; j++)
    {
        inner_prod += temp[j];
    }

    // Just processed the dot multiplication of elements that are multiples of the first 4. If len is not a multiple of 4, then there is a little tail to deal with
    for (; i < len; ++i)
    {
        inner_prod += x[i] * y[i]; //Continue to accumulate the product of the little tail
    }
    return inner_prod; //You're done
}

/**
 * 
 * dot _mm_dp_ps  float版本
 * 
**/

float dot_mm128(const float *x, const float *y, const long len)
{
    float inner_prod = 0.0f;
    __m128 X, Y;                   //Declare two variables stored in the 128-bit special register of SSE
    __m128 acc = _mm_setzero_ps(); // Declare a variable stored in a 128-bit special register in SSE to store the result of X+Y, the initial value is 0
    float temp[4];                 //Store the parameters of the intermediate variables

    long i;
    for (i = 0; i + 4 < len; i += 4)
    {                                            //128-bit special register, which can handle 4 groups of 32-bit variable operations at one time
        X = _mm_loadu_ps(x + i);                 // Load x to X (because 128 bits can store four 32-bit data, the default is to load 4 consecutive parameters at a time)
        Y = _mm_loadu_ps(y + i);                 //Same as above
        acc = _mm_add_ps(acc, _mm_mul_ps(X, Y)); //x*y, the sum of x1*y1 in each round, the sum of x2*y2, the sum of x3*y3, the sum of x4*y4, and the final result The four sums are placed in the 128-bit register of acc.
    }
    _mm_storeu_ps(&temp[0], acc);                       // Load 4 32-bit data in acc into memory
    inner_prod = temp[0] + temp[1] + temp[2] + temp[3]; //dot multiplication sum

    // Just processed the dot multiplication of elements that are multiples of the first 4. If len is not a multiple of 4, then there is a little tail to deal with
    for (; i < len; ++i)
    {
        inner_prod += x[i] * y[i]; //Continue to accumulate the product of the little tail
    }
    return inner_prod; //You're done
}
static inline float horizontal_add_v256(__m256 v)
{
    __m256 x1 = _mm256_hadd_ps(v, v);
    __m256 x2 = _mm256_hadd_ps(x1, x1);
    __m128 x3 = _mm256_extractf128_ps(x2, 1);
    __m128 x4 = _mm_add_ss(_mm256_castps256_ps128(x2), x3);

    return _mm_cvtss_f32(x4);
}

__attribute__((noinline)) float dot_mm256_horadd(const float *x, const float *y, const long len)
{
    __m256 ymm_sum0 = _mm256_setzero_ps();
    __m256 ymm_sum1 = _mm256_setzero_ps();

    for (size_t i = 0; i < len; i += 16)
    {
        ymm_sum0 = _mm256_fmadd_ps(_mm256_loadu_ps(x + i),
                                   _mm256_loadu_ps(y + i),
                                   ymm_sum0);
        ymm_sum1 = _mm256_fmadd_ps(_mm256_loadu_ps(x + i + 8),
                                   _mm256_loadu_ps(y + i + 8),
                                   ymm_sum1);
    }
    return horizontal_add_v256(_mm256_add_ps(ymm_sum0, ymm_sum1));
}

__attribute__((noinline)) float dot_mm512(const float *x, const float *y, const long len)
{
    float inner_prod = 0.0f;
    __m512 X, Y;                      //Declare two variables stored in the 128-bit special register of SSE
    __m512 acc = _mm512_setzero_ps(); // Declare a variable stored in a 128-bit special register in SSE to store the result of X+Y, the initial value is 0
    float temp[16];                   //Store the parameters of the intermediate variables

    long i;
    for (i = 0; i + 16 < len; i += 16)
    {                                                  //128-bit special register, which can handle 4 groups of 32-bit variable operations at one time
        X = _mm512_loadu_ps(x + i);                    // Load x to X (because 128 bits can store four 32-bit data, the default is to load 4 consecutive parameters at a time)
        Y = _mm512_loadu_ps(y + i);                    //Same as above
        acc = _mm512_add_ps(acc, _mm512_mul_ps(X, Y)); //x*y, the sum of x1*y1 in each round, the sum of x2*y2, the sum of x3*y3, the sum of x4*y4, and the final result The four sums are placed in the 128-bit register of acc.
    }
    _mm512_storeu_ps(&temp[0], acc); // Load 4 32-bit data in acc into memory
    //dot multiplication sum
    long j;
    for (j = 0; j < 16; j++)
    {
        inner_prod += temp[j];
    }

    // Just processed the dot multiplication of elements that are multiples of the first 4. If len is not a multiple of 4, then there is a little tail to deal with
    for (; i < len; ++i)
    {
        inner_prod += x[i] * y[i]; //Continue to accumulate the product of the little tail
    }
    return inner_prod; //You're done
}

static inline float horizontal_add_v512(__m512 v)
{
    __m256 low = _mm512_castps512_ps256(v);
    __m256 high = _mm256_castpd_ps(_mm512_extractf64x4_pd(
        _mm512_castps_pd(v), 1));

    return horizontal_add_v256(low + high);
}

__attribute__((noinline)) float dot_fma512_horadd(const float *x, const float *y, const long len)
{
    __m512 zmm_sum0 = _mm512_setzero_ps();
    __m512 zmm_sum1 = _mm512_setzero_ps();

    for (size_t i = 0; i < len; i += 32)
    {
        zmm_sum0 = _mm512_fmadd_ps(_mm512_loadu_ps(x + i),
                                   _mm512_loadu_ps(y + i),
                                   zmm_sum0);
        zmm_sum1 = _mm512_fmadd_ps(_mm512_loadu_ps(x + i + 16),
                                   _mm512_loadu_ps(y + i + 16),
                                   zmm_sum1);
    }
    return horizontal_add_v512(_mm512_add_ps(zmm_sum0, zmm_sum1));
}

__attribute__((noinline)) float dot512fma2(float *x1, float *x2, size_t len)
{
    // assert(len % 32 == 0);
    if (len % 32 != 0)
    {
        return 0;
    }
    __m512 sum = _mm512_setzero_ps();
    if (len > 31)
    {
        size_t limit = len - 31;
        for (size_t i = 0; i < limit; i += 32)
        {

            __m512 v11 = _mm512_loadu_ps(x1 + i);
            __m512 v21 = _mm512_loadu_ps(x2 + i);
            __m512 v12 = _mm512_loadu_ps(x1 + i + 16);
            __m512 v22 = _mm512_loadu_ps(x2 + i + 16);
            sum = _mm512_fmadd_ps(v11, v21, sum);
            sum = _mm512_fmadd_ps(v12, v22, sum);
        }
    }
    float buffer[16];
    _mm512_storeu_ps(buffer, sum);
    return buffer[0] + buffer[1] + buffer[2] + buffer[3] + buffer[4] + buffer[5] +
           buffer[6] + buffer[7] + buffer[8] + buffer[9] + buffer[10] +
           buffer[11] + buffer[12] + buffer[13] + buffer[14] + buffer[15];
}

__attribute__((noinline)) float dot512fma4(float *x1, float *x2, size_t len)
{
    // assert(len % 32 == 0);
    if (len % 64 != 0)
    {
        return 0;
    }
    __m512 sum = _mm512_setzero_ps();
    if (len > 63)
    {
        size_t limit = len - 63;
        for (size_t i = 0; i < limit; i += 64)
        {

            __m512 v11 = _mm512_loadu_ps(x1 + i);
            __m512 v21 = _mm512_loadu_ps(x2 + i);
            __m512 v12 = _mm512_loadu_ps(x1 + i + 16);
            __m512 v22 = _mm512_loadu_ps(x2 + i + 16);
            __m512 v13 = _mm512_loadu_ps(x1 + i + 32);
            __m512 v23 = _mm512_loadu_ps(x2 + i + 32);
            __m512 v14 = _mm512_loadu_ps(x1 + i + 48);
            __m512 v24 = _mm512_loadu_ps(x2 + i + 48);
            sum = _mm512_fmadd_ps(v11, v21, sum);
            sum = _mm512_fmadd_ps(v12, v22, sum);
            sum = _mm512_fmadd_ps(v13, v23, sum);
            sum = _mm512_fmadd_ps(v14, v24, sum);
        }
    }
    float buffer[16];
    _mm512_storeu_ps(buffer, sum);
    return buffer[0] + buffer[1] + buffer[2] + buffer[3] + buffer[4] + buffer[5] +
           buffer[6] + buffer[7] + buffer[8] + buffer[9] + buffer[10] +
           buffer[11] + buffer[12] + buffer[13] + buffer[14] + buffer[15];
}

__attribute__((noinline)) float dot512fma2_align(float *x1, float *x2, size_t len)
{
    // assert(len % 32 == 0);
    if (len % 32 != 0)
    {
        return 1;
    }
    __m512 sum = _mm512_setzero_ps();
    if (len > 31)
    {
        size_t limit = len - 31;
        for (size_t i = 0; i < limit; i += 32)
        {

            __m512 v11 = _mm512_load_ps(x1 + i);
            __m512 v21 = _mm512_load_ps(x2 + i);
            __m512 v12 = _mm512_load_ps(x1 + i + 16);
            __m512 v22 = _mm512_load_ps(x2 + i + 16);
            sum = _mm512_fmadd_ps(v11, v21, sum);
            sum = _mm512_fmadd_ps(v12, v22, sum);
        }
    }
    float buffer[16];
    _mm512_store_ps(buffer, sum);
    return buffer[0] + buffer[1] + buffer[2] + buffer[3] + buffer[4] + buffer[5] +
           buffer[6] + buffer[7] + buffer[8] + buffer[9] + buffer[10] +
           buffer[11] + buffer[12] + buffer[13] + buffer[14] + buffer[15];
}

void test_func()
{
    return;
}

int main()
{
    // printf("%d\n", find_last_set_64((uint64_t)4));
    float *d1 = NULL;
    float *d2 = NULL;
    float *d3 = NULL;
    float *d4 = NULL;
    posix_memalign(&d1, ALIGNED_BYTES, sizeof(float) * N);
    posix_memalign(&d2, ALIGNED_BYTES, sizeof(float) * N);
    posix_memalign(&d3, 64, sizeof(float) * N);
    posix_memalign(&d4, 64, sizeof(float) * N);

    for (int i = 0; i < N; i++)
    {
        d1[i] = (double)rand() / RAND_MAX;
        d2[i] = (double)rand() / RAND_MAX;
        d3[i] = (double)rand() / RAND_MAX;
        d4[i] = (double)rand() / RAND_MAX;
    }

    clock_t start_time, end_time;
    float r1 = 0.0;

    start_time = clock();
    r1 = dot_raw(d1, d2, N);
    end_time = clock();
    printf("Raw dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot_mm128(d1, d2, N);
    end_time = clock();
    printf("MM128 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot_mm256(d1, d2, N);
    end_time = clock();
    printf("MM256 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot_mm256_horadd(d1, d2, N);
    end_time = clock();
    printf("MM256_horadd dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot_mm512(d1, d2, N);
    end_time = clock();
    printf("MM512 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot512fma2(d1, d2, N);
    end_time = clock();
    printf("MM512fma2 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot512fma4(d1, d2, N);
    end_time = clock();
    printf("MM512fma4 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot_fma512_horadd(d1, d2, N);
    end_time = clock();
    printf("MM512_fma512_horadd dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    r1 = dot_raw(d3, d4, N);
    start_time = clock();
    r1 = dot512fma2_align(d3, d4, N);
    end_time = clock();
    printf("MM512fma2_align dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    free(d1);
    free(d2);
    free(d3);
    free(d4);
}