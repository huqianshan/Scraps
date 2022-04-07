#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct flexible
{
    int a;
    short b;
    double c;
    char arr[0]; // 不占空间 非标准扩展 某些编译器支持
    //char arr[]; // c99标准 必须在结构体最后，且不能为唯一成员
    /* data */
} Flex;

int main(int argc, char const *argv[])
{

    char str[] = "1234567890abc\n";
    printf("%lu %lu\n", sizeof(Flex), sizeof(str));

    Flex *flex = (Flex *)malloc(sizeof(Flex) + 100 * sizeof(char));
    memcpy(flex->arr, str, sizeof(str));
    printf("%lu \n", sizeof(Flex));
    printf("%s\n", flex->arr);
    free(flex);
    return 0;
}
