#include <stdio.h>

int add(int a, int b) { return a + b; }

int minus(int a, int b) { return a - b; }

typedef int (*funcptr)(int, int);

void t1() {
#define op(_) fp##_

    int a = 12, b = 23;
    funcptr op(1) = add, op(2) = minus;
    printf("%d+%d=%d\n", a, b, op(1)(a, b));
}

int oper(funcptr ope, int a, int b) { return ope(a, b); }

void t2() {
    int a = 10, b = 20;
    printf("%d+%d=%d\n", a, b, oper(add, a, b));
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}