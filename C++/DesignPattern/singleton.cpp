#include <iostream>
using namespace std;

class Single
{

    friend class DoSingle; // 友元方式
private:
    Single()
    {
        cout << "Construct" << endl;
    }
    static Single *instance;
    Single(Single &s) = delete;             //禁止拷贝构造函数
    Single &operator&=(Single &s) = delete; //禁止赋值构造函数

public:
    ~Single()
    {
        cout << "Exited" << instance << endl;
    }
    static Single *getSingleInstance()
    {

        if (instance == nullptr)
        {
            instance = new Single();
            cout << "HERE" << endl;
        }
        return instance;
    }
};
Single *Single::instance = nullptr;

class DoSingle
{
public:
    DoSingle()
    {
        Single a;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    // Single a;
    // Single b;
    cout << "ret finished" << endl;
    // printf("%d \n", sizeof(Single));
    // Single *test = Single::getSingleInstance();
    // cout << "init finished" << endl;
    DoSingle b;
}
