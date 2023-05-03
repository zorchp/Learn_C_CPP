#include <stdio.h>


int add(int a, int b) { return a + b; }

int minus(int a, int b) { return a - b; }

typedef int (*funcptr)(int, int);


void t1() {
    int a = 10, b = 20;
    funcptr op[128] = {NULL};
    char op1 = '-', op2 = '+';
    op[op1] = minus;
    op[op2] = add;
    printf("%d%c%d=%d\n", a, op1, b, op[op1](a, b));
    printf("%d%c%d=%d\n", a, op2, b, op[op2](a, b));
    /*
    10-20=-10
    10+20=30
    */
}

void t2() {
    int a = 10, b = 20;
    int (*op[128])(int, int) = {NULL}; // do not use typedef
    char op1 = '-', op2 = '+';
    op[op1] = minus;
    op[op2] = add;
    printf("%d%c%d=%d\n", a, op1, b, op[op1](a, b));
    printf("%d%c%d=%d\n", a, op2, b, op[op2](a, b));
    /*
    10-20=-10
    10+20=30
    */
}

int main(int argc, char const *argv[]) {
    t1();
    t2();
    return 0;
}