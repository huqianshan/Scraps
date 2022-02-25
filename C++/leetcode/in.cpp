#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    int a, b;
    char c;
    while (cin >> a >> c >> b)
    {
        printf("a:%d  b:%d\n", a, b);
    }
    // while (scanf("%d%c%d\n", &a, &b, &c) == 0)
    scanf("%d,%d\n", &a, &b);
    {
        printf("a:%d  b:%d c:%c\n", a, b, c);
    }
    EOF;
    return 0;
}
