#include <stdio.h>

void print(void) {
    static int a = 0;
    printf("静态局部变量a=%d\n", a++);
}

void t1() {
    print();
    print();
    // 静态局部变量在初始化以后，再次执行该函数时静态局部变量保存的是上一次的运行结果。
    /*
    静态局部变量a=0
    静态局部变量a=1*/
}

void print1(void) {
    static int a = 0;
    printf("静态局部变量a=%d\n", ++a);
}

void t2() {
    print1();
    print1();
    /*
    静态局部变量a=1
    静态局部变量a=2*/
}
int main(void) {
    t1();
    // t2();

    return 0;
}