/**
 * @file write_combining_buffer.c
 * @author gcfs-optane (1196455147@qq.com)
 * @brief no use
 * @version 0.1
 * @date 2022-05-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "tsc.h"
#include <stdio.h>
#include <stdlib.h>

#define ITEMS (1 << 23)
#define MASK (ITEMS - 1)
#define N ((uint64_t)1 << 28)

#define NUM (12)
#define TYPE uint64_t

TYPE *arrays[NUM];

uint64_t runCaseOne()
{
    uint64_t s = bench_start();
    int i = (int)(N - 1);
    while ((--i) != 0)
    {
        int slot = i & MASK;
        for (int j = 0; j < NUM; j++)
        {
            arrays[j][slot] = (TYPE)i;
        }
    }
    uint64_t e = bench_end();
    // printf("one: begin: %lu end %lu dur: %lf\n", s, e, e - s);
    return e - s;
}

uint64_t runCaseTwo()
{
    uint64_t s = bench_start();
    int i = N - 1;
    while ((--i) != 0)
    {
        int slot = i & MASK;
        for (int j = 0; j < 2; j++)
        {
            arrays[j][slot] = (TYPE)i;
        }
    }

    i = N - 1;
    while ((--i) != 0)
    {
        int slot = i & MASK;
        for (int j = 2; j < 5; j++)
        {
            arrays[j][slot] = (TYPE)i;
        }
    }

    i = N - 1;
    while ((--i) != 0)
    {
        int slot = i & MASK;
        for (int j = 6; j < 9; j++)
        {
            arrays[j][slot] = (TYPE)i;
        }
    }

    i = N - 1;
    while ((--i) != 0)
    {
        int slot = i & MASK;
        for (int j = 9; j < 12; j++)
        {
            arrays[j][slot] = (TYPE)i;
        }
    }

    return bench_end() - s;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < NUM; i++)
    {
        arrays[i] = malloc(ITEMS * sizeof(TYPE));
    }

    for (int i = 1; i <= 3; i++)
    {
        printf("SingleLoop %2d duration: %16lu us\n", i, cycles_to_us(runCaseOne()));

        printf("TwoLoop    %2d duration: %16lu us\n", i, cycles_to_us(runCaseTwo()));
    }

    TYPE result = 0;
    for (int i = 0; i < NUM; i++)
    {
        result += arrays[i][0];
    }
    printf("Result: %4lu\n", result);
    for (int i = 0; i < NUM; i++)
    {
        free(arrays[i]);
    }
    return 0;
}
