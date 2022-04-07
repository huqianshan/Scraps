#include <iostream>
#include <list>
using namespace std;

class Base
{
protected:
    int a;
    void print()
    {
        cout << "" << a << "" << endl;
    }

public:
    Base(int num) : a(num){};
    void show()
    {
        print();
    }
};

class Derived : public Base
{
protected:
    int b;

public:
    Derived(int num) : Base(num - 1), b(num) { cout << "in d constructor" << this->a << "" << endl; };
    void test()
    {
        cout << "" << a << "" << endl;
    }
};

void test()
{
    const int count = 10;

    int *linear = new int[count * count];
    for (int i = 0; i < count * count; i++)
    {
        linear[i] = i;
    }
    int **T;
    T = new int *[count];
    for (size_t i = 0; i < count; i++)
    {
        T[i] = linear + i * count;
    }
    for (size_t i = 0; i < count; i++)
    {
        cout << "T[" << i << "]: " << T[i] << " value: " << *(T[i] + 1) << endl;
        /* code */
    }
}

int main(int argc, char const *argv[])
{

    Base base(3);
    // cout << "" << base.a << "" << endl; // 不能被外部访问
    // base.print();
    base.show();

    Derived derived(4);
    derived.test();

    list<int> nums = {1, 2, 4, 8, 16};
    cout << " " << *nums.begin() << " " << nums.front() << endl;
    return 0;
}
