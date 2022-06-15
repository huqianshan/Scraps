#include "assembly.h"
#include <stdint.h>
#include <stdio.h>

//test-and-set uint8_t
static inline uint8_t tas_uint8(volatile uint8_t *addr)
{
    uint8_t oldval;
    __asm__ __volatile__("xchgb %0,%1"
                         : "=q"(oldval), "=m"(*addr)
                         : "0"((unsigned char)0xff), "m"(*addr)
                         : "memory");
    return (uint8_t)oldval;
}

int main(int argc, char **argv)
{
    // a->b

    int a = 10, b;
    asm("movl %1,%%eax \n\t"
        "movl %%eax,%0 \n\t"
        : "=r"(b)
        : "r"(a)
        : "%eax");

    printf("a:%d b:%d\n", a, b);
    uint8_t c = 1;
    uint8_t ret = tas_uint8(&c);
    printf("%d %d\n", (uint32_t)c, (uint32_t)ret);
}