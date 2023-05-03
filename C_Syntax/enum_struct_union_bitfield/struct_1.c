#include <stdio.h>


void t1() {
    struct P {
        int a;
        // void fun(){};//cannot use func in struct by C
    };
    struct P p1, p2; // must add `struct` keyword
}

void t2() {
    // or using `typedef`
    typedef struct p {
        int a;
    } P;
    P p1, p2;
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}