#include <iostream>
#include <vector>
struct ht_entry
{

    std::vector<int> *entries; // 16 bytes
    // std::vector<float> bk;         // 12 bytes{2
    std::vector<double> *test;
    ht_entry()
    {
        entries = nullptr;
        std::vector<int> t(10);
        entries = &(t);
        test = nullptr;
    }
};

int main(int argc, char *argv[])
{
    // test_type_size();
    // test_struct_padding();
    // test_struct_address();
    // test_malloc_address();

    std::cout << sizeof(ht_entry) << std::endl;
    return 0;
}