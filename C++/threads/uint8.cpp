#include <iostream>

#include <stdint.h>
using namespace std;
/**
 * uint8_t 类型变量转化为字符串以及字符串转化为 uint8_t 类
 * 型变量都要注意, uint8_t类型变量转化为字符串时得到的会是
 * ASCII码对应的字符, 字符串转化为 uint8_t 变量时, 会
 * 将字符串的第一个字符赋值给变量
 */
using vt = volatile int;
int main()
{
    /*     int a = 3;
    vt *s = &a;
    cout << s << " " << *s << endl; */

    uint8_t s = 65;
    printf("%d%c\n", s, s);
    cout << s << endl;
}