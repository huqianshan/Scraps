
#include <immintrin.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMD 1
#define SIMD_CMP8(src, key)                                      \
    do                                                           \
    {                                                            \
        const __m256i key_data = _mm256_set1_epi8(key);          \
        __m256i seg_data = _mm256_loadu_si256((__m256i *)(src)); \
        __m256i rv_mask = _mm256_cmpeq_epi8(seg_data, key_data); \
        mask = _mm256_movemask_epi8(rv_mask);                    \
    } while (0)

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
#define N (64000000)
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
 * dot _mm256_dp_ps  double版本
 * 
**/

float dot_mm256(float *a, float *b, int n)
{
    double res = 0.0;
    int k = n / 4 + 1;
    for (int i = 0; i < k; i++)
    {
        __m256 ai = _mm256_loadu_ps(a + i * 4); //不对齐加载数据
        __m256 bi = _mm256_loadu_ps(b + i * 4);
        __m256 r = _mm256_dp_ps(ai, bi, 0xF1);
        res += r[0] + r[5];
        // res += r[5];
    }
    return res;
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

float dot_mm512(const float *x, const float *y, const long len)
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
    r1 = dot_mm512(d1, d2, N);
    end_time = clock();
    printf("MM512 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    r1 = dot512fma2(d1, d2, N);
    end_time = clock();
    printf("MM512fma2 dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    r1 = dot_raw(d3, d4, N);
    start_time = clock();
    r1 = dot512fma2_align(d3, d4, N);
    end_time = clock();
    printf("MM512fma2_align dot:%f\n", r1);
    printf("pall times = %fs\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    free(d1);
    free(d2);
}