#include <stdio.h>

struct str {
    int a;
    int b;
    int c;
};

union uni {
    char a;
    int b;
    int c;
};

int main() {
    struct str x;
    union uni y;

    printf("结构体所占的内存大小为%lu字节\n", sizeof(x));
    printf("结构体中成员变量a的地址为%p\n", &x.a);
    printf("结构体中成员变量b的地址为%p\n", &x.b);
    printf("结构体中成员变量c的地址为%p\n\n", &x.c);

    printf("共用体所占的内存大小为%lu字节\n", sizeof(y));
    printf("共用体中成员变量a的地址为%p\n", &y.a);
    printf("共用体中成员变量b的地址为%p\n", &y.b);
    printf("共用体中成员变量c的地址为%p\n", &y.c);

    return 0;
    /*
    结构体所占的内存大小为12字节
    结构体中成员变量a的地址为0x16fc03060
    结构体中成员变量b的地址为0x16fc03064
    结构体中成员变量c的地址为0x16fc03068

    共用体所占的内存大小为4字节
    共用体中成员变量a的地址为0x16fc0305c
    共用体中成员变量b的地址为0x16fc0305c
    共用体中成员变量c的地址为0x16fc0305c
    */
}