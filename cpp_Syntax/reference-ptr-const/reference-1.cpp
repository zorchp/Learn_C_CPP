#include <bits/stdc++.h>
using namespace std;


void t1_reference() {
    int a = 10, A = 100;
    int& b = a; // b是a的别名
    // b = 20;
    // b = A;
    // int* const bb = &a;//等价于指针常量
    // printf("a=%d, b=%d, bb=%d\n", a, b, *bb);
    // printf("a=%p, b=%p, bb=%p\n", &a, &b, &bb);

    // *bb = 30;//值可以通过解引用方式改变
    // bb = &B;//指向不能变
    // printf("a=%d, b=%d\n", a, b);
    // printf("a=%p, b=%p\n", &a, &b);

    int c = 20;
    b = c; // ref可以通过赋值改变大小, 但是指向的地址并没变
    printf("a=%d, c=%d, b=%d\n", a, c, b);
    printf("a=%p, c=%p, b=%p\n", &a, &c, &b);
    /*
    a=20, c=20, b=20
    a=0x16b6df08c, c=0x16b6df07c, b=0x16b6df08c
    */
}

void const_ref_1() {
    int a = 10;
    const int& b = a;
    a = 20;
    printf("a=%d, b=%d\n", a, b);
    printf("a=%p, b=%p\n", &a, &b);
    const int& c = a;
    int d = 40;
    // b = d;
    // c = 30;//error 不能给常量赋值
}

void const_ref_2() {
    const int a = 20;
    const int& b = a;
    // a = 20;
    // b = 20;
    const int& c = 12;
}

void const_ref_3() {
    double a = 1.1;
    // int& c = a; // a是double类型，c是int，a赋值给 c时要生成一个临时变量
    // 也就是说c引用的是这个带有常性的临时变量，所以不能赋值。
    const int& b = a;
    printf("a=%f, b=%d\n", a, b);
    printf("a=%p, b=%p\n", &a, &b);
    /*
    a=1.100000, b=1
    a=0x16cfdf088, b=0x16cfdf07c
    */
    int d = 20;
}


int main(int argc, char const* argv[]) {
    t1_reference();
    // const_ref_1();
    // const_ref_2();
    // const_ref_3();
    return 0;
}