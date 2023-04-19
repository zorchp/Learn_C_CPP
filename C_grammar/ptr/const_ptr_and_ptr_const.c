#include <stdio.h>
#include <stdlib.h>

void t1() {
    // 常量指针, 即指向常量的指针,不能通过解引用的方式修改其指向的值,
    // 但是可以改变指针的指向 pointer const: a pointer which point to a constant
    // variable
    int a = 10;

    const int* p1 = &a;
    // int const* p2 = &a;
    // *a = 20;//error
    a = 20;
    printf("a=%d\n", a);
    printf("p1=%p\n", p1);
    // access a:
    printf("*p1=%d\n", *p1);
    // change ptr
    int c = 30;
    p1 = &c;
    printf("p1=%p\n", p1);
    // access c:
    printf("*p1=%d\n", *p1);
    //  *p1 = 100;// change a: error

    /*
    a=20
    p1=0x16d1d709c
    *p1=20
    p1=0x16d1d708c
    *p1=30
    */
}

void t2() {
    // 指针常量, 指针类型的常量, 可以指向非常量,
    // 可以通过解引用方式改变指向的(非常量)值,
    // 但是不能改变指针的指向(指向已经确定) const pointer: a constant pointer
    // 相当于C++的引用
    int a = 10;
    int* const p1 = &a;
    printf("p1=%p\n", p1);
    // access a:
    printf("*p1=%d\n", *p1);
    // change a:
    *p1 = 20;
    printf("p1=%p\n", p1);
    // access a:
    printf("*p1=%d\n", *p1);
    // change ptr: error
    int b = 30;
    // p1 = &b; //error
}
void t3() { // 指向常量的常量指针, 用处较少, 若对常量进行指向, 会报warning
    const int a = 10;
    // int* const p = &a;
    /*warning: initialization discards 'const' qualifier from pointer target
     * type*/
}

void t4() {
    const int a = 10;
    const int* const p = &a;
    //
    // warning: initializing 'int *const' with an expression
    // of type 'const int *' discards qualifiers
    // [-Wincompatible-pointer-types-discards-qualifiers]
    printf("p=%p,*p=%d.\n", p, *p);
}

void t5(){
    const int a=10;
    int *p=&a;
}

int main() {
    t1();
    // t2();
    t3();
    t4();
    t5();
    return 0;
}