void add_asm()
{
    int foo = 10, bar = 15;
    __asm__ __volatile__("addl %%ebx, %%eax"
                         : "= a"(foo)
                         : "a"(foo), "b"(bar));
}

void add_func()
{
    int foo = 10, bar = 15;
    foo += bar;
}