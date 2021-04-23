#include <thread>
#include <atomic>
#include <cassert>

std::atomic<bool> x = {false};
std::atomic<bool> y = {false};
std::atomic<int> z = {0};

void write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst))
        ;
    if (y.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst))
        ;
    if (x.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}

/* int main()
{
    while (true)
    {
        std::thread a(write_x);
        std::thread b(write_y);
        std::thread c(read_x_then_y);
        std::thread d(read_y_then_x);
        a.join();
        b.join();
        c.join();
        d.join();
        assert(z.load() != 0); // will never happen
    }
}
 */

// wrong  dependency-ordered synchronization for pointer-mediated publication
#include <thread>
#include <atomic>
#include <cassert>
#include <string>

std::atomic<std::string *> ptr;
int data;

void producer()
{
    std::string *p = new std::string("Hello");
    data = 42;
    ptr.store(p, std::memory_order_release);
}

void consumer()
{
    std::string *p2;
    while (!(p2 = ptr.load(std::memory_order_consume)))
        ;
    assert(*p2 == "Hello"); // never fires: *p2 carries dependency from ptr
    assert(data == 42);     // may or may not fire: data does not carry dependency from ptr
}

int main()
{
    while (true)
    {
        data = 3;
        std::thread t1(producer);
        std::thread t2(consumer);
        t1.join();
        t2.join();
    }
}