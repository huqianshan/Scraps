#include <stdio.h>
#include "assembly.h"


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
}