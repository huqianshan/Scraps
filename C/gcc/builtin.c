#include <immintrin.h>
#include <stdint.h>
#include <stdio.h>

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

int main()
{
    printf("%d\n", find_last_set_64((uint64_t)4));
}