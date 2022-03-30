#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
void reference(int &v)
{
    std::cout << "左值引用" << std::endl;
}
void reference(int &&v)
{
    std::cout << "右值引用" << std::endl;
}
template <typename T>
void pass(T &&v)
{
    std::cout << " 右值传递" << std::endl;
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
}

template <typename T>
void pass(T &v)
{
    std::cout << " 引用传递" << std::endl;
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
}

/* template <typename T>
void pass(T v)
{
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
} */

int main()
{
    std::cout << "传递右值:" << std::endl;
    pass(1);

    std::cout << "传递左值:" << std::endl;
    int v = 1;
    pass(v);

    vector<int> q{1, 2, 3, 4, 5, 6, 7};
    // 在这里想把大于2的元素都删除
    for (auto it = q.begin(); it != q.end();)
    {
        if (*it > 2)
        {
            it = q.erase(it); // 这里就会发生迭代器失效
        }
        else
        {
            it++;
        }
    }
    // 打印结果
    for (auto it = q.begin(); it != q.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int stack_v = 1;
    const int const_v = 1;
    static int static_v = 1;
    static int static_vn; // 未初始化
    int *heap_v = new int[3]{1, 4, 5};
    printf("stack:%20p\nconst:%20p\nstatic:%20p\nsta_not:%20p\nheap:%20p\n", &stack_v, &const_v, &static_v, &static_vn, heap_v);
    // 普通变量是在栈上面，const也是； static是在全局静态变量区，在代码区的上面，
    int &ref = stack_v;
    printf("%p \n", (&ref));
    string s = "123";
    const string cs = "123";
    static const string scs;
    static const string scsi = "123";
    printf("\n%p \n%p\n%p\n%p\n", &s, &cs, &scs, &scsi);

    const char *a = reinterpret_cast<const char *>("stringa");
    char b[] = "stringb";
    printf("%p %p\n", a, b);
    while (1)
        ;
        
    return 0;
}