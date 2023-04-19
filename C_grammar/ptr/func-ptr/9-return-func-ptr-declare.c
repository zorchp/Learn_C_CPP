#include <stdio.h>

int add(int, int);
int (*func(int, int))(int, int);

int main() {
    int a = 5, b = 5;
    int a1 = 3, b1 = 3;
    // 函数调用, `func(a, b)`返回一个函数指针
    // 后面的`(a,b)`才是真正进行相加运算的形参
    int ans = func(a1, b1)(a, b);
    printf("ans=%d\n", ans);
    return 0;
    /*
    a1=3
    b1=3
    ans=10
    */
}

int add(int x, int y) { return x + y; }

// 返回函数指针的函数, 返回的函数指针,形参列表为两个int, 返回值为int
int (*func(int a1, int b1))(int, int) {
    printf("a1=%d\n", a1);
    printf("b1=%d\n", b1);
    return add;
}
