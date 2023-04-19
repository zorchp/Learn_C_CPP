#include <stdio.h>

/*
当相邻位域的类型相同时，如果其位宽之和小于该类型所占用的位宽大小，那么后面的位域紧邻前面的位域存储，直到不能容纳为止；
如果位宽之和大于类型所占用的位宽大小，那么就从下一个存储单元开始存放。
*/
void t1() {
    struct _data {
        char a : 6;
        char b : 2; // 6+2=8/8=1byte
        char c : 7; // 1+1=2bytes
    } data;
    printf("位域变量data起始地址为: %p\n", &data);
    printf("位域变量data占用内存大小为:%lu字节\n", sizeof(data));
    /*
    位域变量data起始地址为: 0x104a00000
    位域变量data占用内存大小为:2字节
    */
}

void t2() {
    struct _data {
        char a : 6;
        char b : 4; // 6+4=10/8+1=2bytes
        char c : 7; // 2+1=2bytes
    } data;
    printf("位域变量data起始地址为: %p\n", &data);
    printf("位域变量data占用内存大小为:%lu字节\n", sizeof(data));
    /*
    位域变量data起始地址为: 0x16f88300d
    位域变量data占用内存大小为:3字节
    */
}

/*
默认情况下，位域结构中的字节对齐方式由其中占用字节数最大的类型所决定。
在前面定义的位域中，占用内存最大的是int型，占用4字节，所以使用4字节对齐。
*/
void t3() {
    struct _data {
        char a : 6; // 1
        int b : 22; // 4
        char c : 7; // 1,但需要考虑四字节对齐
    } data;
    printf("位域变量data起始地址为: %p\n", &data);
    printf("位域变量data占用内存大小为:%lu字节\n", sizeof(data));
    /*
    位域变量data起始地址为: 0x16f46b008
    位域变量data占用内存大小为:8字节
    */
    data.a = '0';
    data.b = 3646464;
    data.c = 'c';
    printf("%p\n", data.a);
    printf("%p\n", data.b);
    printf("%p\n", data.c);
    /*
    位域变量data起始地址为: 0x16f98f028
    位域变量data占用内存大小为:8字节
    0xfffffff0
    0xfff7a400
    0xffffffe3
    */
}

void t4() {
    struct _data {
        int b : 22;
        char a : 6;
        char c : 7;
    } data;

    printf("位域变量data起始地址为: %p\n", &data);
    printf("位域变量data占用内存大小为:%lu字节\n", sizeof(data));
    /*
    位域变量data起始地址为: 0x16f717028
    位域变量data占用内存大小为:8字节
    */
}

void tt() {
    typedef struct tag {
        char hour : 4;
        unsigned second : 6;
        unsigned minute : 6;
    } Time;

    printf("%lu\n", sizeof(unsigned));       // 4
    printf("%lu\n", sizeof(unsigned short)); // 2
    printf("%lu\n", sizeof(Time));           // 4
}

void t5() {
#pragma pack(2)
    /*
    通过“#pragma pack (2)”来指定采用2字节对齐。
    */

    struct _data {
        int a : 16; // 2
        char b : 4; // 1
        char c : 6; // 1
    } data;

    printf("位域变量data起始地址为: %p\n", &data);
    printf("位域变量data占用内存大小为:%lu字节\n", sizeof(data));
    /*
    位域变量data起始地址为: 0x16db67028
    位域变量data占用内存大小为:4字节
    */
}

void t6() {
    // #pragma pack (2)
    // 指定字节对齐值, 但未使用的位域段
    struct _data {
        int a : 16;
        unsigned char b : 5;
        char c : 5;
    } data;


    int *p = (int *)&data;

    printf("位域结构的起始地址为:%p\n\n", p);
    data.a = 2;

    printf("整型指针p所指向的单元存储的值为:%d\n", *p);
    printf("位域a的值为:%d\n", data.a);

    char *p1 = (char *)(p + 1);
    data.b   = 18;
    printf("\n字符指针p1所指向的单元存储的值为:%d\n", *p1);
    printf("位域b的值为:%d\n", data.b);

    data.c = 255;
    char *p2;
    p2 = p1 + 1;
    printf("\n字符指针p2所指向的单元存储的值为:%d\n", *p2);
    printf("位域c的值为:%d\n", data.c);
    /*
    位域结构的起始地址为:0x16afe3010

    整型指针p所指向的单元存储的值为:81854466
    位域a的值为:2

    字符指针p1所指向的单元存储的值为:1
    位域b的值为:18

    字符指针p2所指向的单元存储的值为:0
    位域c的值为:-1
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    // tt();
    // t5();
    t6();
    return 0;
}