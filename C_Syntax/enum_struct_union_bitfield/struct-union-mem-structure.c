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
    x.a = 0x2a3d;
    x.b = 0xc4df;
    x.c = 0x5bac;
    printf("结构体中成员变量a的值为%x\n", x.a);
    printf("结构体中成员变量b的值为%x\n", x.b);
    printf("结构体中成员变量c的值为%x\n\n", x.c);
    y.a = 'a';
    y.b = 0x1345;
    y.c = 0xb548;
    printf("共用体中成员变量a的值为%x\n", y.a);
    //当打印a的值时，因为它在内存中占用的是最低字节的内存，所以打印出来的是最后对共用体变量y的成员c赋值的低字节部分48。
    printf("共用体中成员变量b的值为%x\n", y.b);
    printf("共用体中成员变量c的值为%x\n", y.c);
    /*
    结构体中成员变量a的值为2a3d
    结构体中成员变量b的值为c4df
    结构体中成员变量c的值为5bac

    共用体中成员变量a的值为48
    共用体中成员变量b的值为b548
    共用体中成员变量c的值为b548
    */
    return 0;
}