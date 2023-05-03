#include <stdio.h>
void print() {
    /*
    非静态变量的局部变量即为自动变量，其类型说明符为auto，
    在C语言中，将函数内没有存储类别说明的变量均视为自动变量，即自动变量可以省去说明符auto。
    */
    auto int a;
    int b;
}

void t1() { print(); }

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}