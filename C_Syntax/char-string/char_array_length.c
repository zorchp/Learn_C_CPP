#include <stdio.h>
#include <string.h>


void t1() {
    char str[8] = "fdsa";
    printf("字符串的长度为:%d\n", strlen(str));
    printf("占用内存的大小为:%d字节\n", sizeof(str));
    /*
    字符串的长度为:4
    占用内存的大小为:8字节
    */
}

void t2() {
    char *str = "Hello";
    printf("strlen(str) = %d\n", strlen(str));
    printf("sizeof(str) = %d\n", sizeof(str));
    printf("sizeof(*str) = %d\n", sizeof(*str));
    /*
    strlen(str) = 5
sizeof(str) = 8
sizeof(*str) = 1*/
}

int main() {
    // t1();
    t2();
    return 0;
}