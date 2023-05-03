#include <stdio.h>


int add(int a, int b) { return a + b; }

int minus(int a, int b) { return a - b; }

typedef int (*funcptr)(int, int);

funcptr oper(char op) {
    switch (op) {
        case '+': return add;
        case '-': return minus;
    }
}

int eval(char op, int a, int b) { return oper(op)(a, b); }

void t1() {
    int a = 10, b = 20;
    char op1 = '-', op2 = '+';
    printf("%d%c%d=%d\n", a, op1, b, eval(op1, a, b));
    printf("%d%c%d=%d\n", a, op2, b, eval(op2, a, b));
    /*
    10-20=-10
    10+20=30
    */
}

int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}