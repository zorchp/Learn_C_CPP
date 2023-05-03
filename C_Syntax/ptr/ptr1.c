#include <stdio.h>

int main() {
    int var = 20;     /* 实际变量的声明 */
    int *ip;          /* 指针变量的声明 */
    ip        = &var; /* 在指针变量中存储 var 的地址 */
    int **ip1 = &ip;
    printf("var 变量的地址: %p\n", &var);
    /* 在指针变量中存储的地址 */
    printf("ip 变量存储的地址: %p\n", ip);
    printf("*ip 变量存储的地址: %p\n", ip1);
    /* 使用指针访问值 */
    printf("*ip 变量的值: %d\n", *ip);
    printf("**ip1 变量的值: %d\n", **ip1);
    return 0;
}