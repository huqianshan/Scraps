#include <functional>
#include <iostream>
#include <random>
using namespace std;

//https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
//https://en.cppreference.com/w/cpp/numeric/random

int main(int argc, char *argv[])
{
    std::random_device rd;                          // 真随机数生成器（但有些编译器没有实现），用于生成伪随机数生成器的种子
    std::mt19937 eng(rd());                         // 使用梅森旋转法作为伪随机数生成器，随机程度较好
    std::uniform_int_distribution<int> dis(10, 20); // 10到20之间的整数均匀分布

    unsigned seed = 2020;
    std::uniform_int_distribution<std::mt19937::result_type> distr(10, 20); //生成实数可用uniform_real_distribution
    std::mt19937 gen(seed);                                                 //可换为std::default_random_engine，但建议用mt19937
    auto randInt = std::bind(distr, gen);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << randInt() << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << rd() << " ";
    std::cout << std::endl;

    return 0;
}