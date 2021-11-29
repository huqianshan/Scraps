/**
 * Memory align & padding - for struct.
 * compile: gcc memory_align.c
 * execute: ./a.out
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// size is 8, 4 + 1, then round to multiple of 4 (int's size),
struct stu_a
{
    int i;
    char c;
};

// size is 16, 8 + 1, then round to multiple of 8 (long's size),
struct stu_b
{
    long l;
    char c;
};

// size is 24, l need padding by 4 before it, then round to multiple of 8 (long's size),
struct stu_c
{
    int i;
    long l;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (long's size),
struct stu_d
{
    long l;
    int i;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (double's size),
struct stu_e
{
    double d;
    int i;
    char c;
};

// size is 24, d need align to 8, then round to multiple of 8 (double's size),
struct stu_f
{
    int i;
    double d;
    char c;
};

// size is 4,
struct stu_g
{
    int i;
};

// size is 8,
struct stu_h
{
    long l;
};

struct bk_entry
{

    uint64_t offset; // 从开始地址的float 偏移量，
    int id;
};

// test - padding within a single struct,
int test_struct_padding()
{
    printf("%s: %ld\n", "stu_a", sizeof(struct stu_a));
    printf("%s: %ld\n", "stu_b", sizeof(struct stu_b));
    printf("%s: %ld\n", "stu_c", sizeof(struct stu_c));
    printf("%s: %ld\n", "stu_d", sizeof(struct stu_d));
    printf("%s: %ld\n", "stu_e", sizeof(struct stu_e));
    printf("%s: %ld\n", "stu_f", sizeof(struct stu_f));

    printf("%s: %ld\n", "stu_g", sizeof(struct stu_g));
    printf("%s: %ld\n", "stu_h", sizeof(struct stu_h));

    printf("%s: %ld\n", "stu_i", sizeof(struct bk_entry));

    return 0;
}

// test - address of struct,
int test_struct_address()
{
    printf("%s: %ld\n", "stu_g", sizeof(struct stu_g));
    printf("%s: %ld\n", "stu_h", sizeof(struct stu_h));
    printf("%s: %ld\n", "stu_f", sizeof(struct stu_f));

    struct stu_g g;
    struct stu_h h;
    struct stu_f f1;
    struct stu_f f2;
    int x = 1;
    long y = 1;

    printf("address of %s: %p\n", "g", &g);
    printf("address of %s: %p\n", "h", &h);
    printf("address of %s: %p\n", "f1", &f1);
    printf("address of %s: %p\n", "f2", &f2);
    printf("address of %s: %p\n", "x", &x);
    printf("address of %s: %p\n", "y", &y);

    // g is only 4 bytes itself, but distance to next struct is 16 bytes(on 64 bit system) or 8 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "g", "h", (long)(&h) - (long)(&g));

    // h is only 8 bytes itself, but distance to next struct is 16 bytes(on 64 bit system) or 8 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "h", "f1", (long)(&f1) - (long)(&h));

    // f1 is only 24 bytes itself, but distance to next struct is 32 bytes(on 64 bit system) or 24 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "f1", "f2", (long)(&f2) - (long)(&f1));

    // x is not a struct, and it reuse those empty space between struts, which exists due to padding, e.g between g & h,
    printf("space between %s and %s: %ld\n", "x", "f2", (long)(&x) - (long)(&f2));
    printf("space between %s and %s: %ld\n", "g", "x", (long)(&x) - (long)(&g));

    // y is not a struct, and it reuse those empty space between struts, which exists due to padding, e.g between h & f1,
    printf("space between %s and %s: %ld\n", "x", "y", (long)(&y) - (long)(&x));
    printf("space between %s and %s: %ld\n", "h", "y", (long)(&y) - (long)(&h));

    return 0;
}

void test_type_size(void)
{
    short a;
    char b;
    int c;
    double d;
    float e;
    long f;
    long long g;
    long double h;

    printf("short: %d\n", sizeof(a));
    printf("char %d\n", sizeof(b));
    printf("int %d\n", sizeof(c));
    printf("double %d\n", sizeof(d));
    printf("float %d\n", sizeof(e));
    printf("long %d\n", sizeof(f));
    printf("long long %d\n", sizeof(g));
    printf("long double %d\n", sizeof(h));
}

void test_malloc_address()
{
    for (int i = 0; i < 100; i++)
    {
        char *a = malloc(i * 3);
        printf("malloc %p void \n", a);
        free(a);
    }
}

struct ht_entry
{

    std::vector<stu_h> info;  // 16 bytes
    std::vector<bk_entry> bk; // 12 bytes{
    ht_entry
    {
    }
}

int
main(int argc, char *argv[])
{
    // test_type_size();
    test_struct_padding();
    // test_struct_address();
    // test_malloc_address();

    std::cout << sizeof(ht_entry) << std::endl;
    return 0;
}