#include <stdio.h>

typedef int (*FUNP)(int, int); // function ptr
int add(int, int);
FUNP fun(int, int);

int main() {
    int a = 5, b = 5;
    int a1 = 3, b1 = 3;
    int ans = fun(a1, b1)(a, b);

    printf("ans=%d\n", ans);
    return 0;
    /* a1=3 */
    /* b1=3 */
    /* ans=10 */
}

int add(int x, int y) { return x + y; }

// 返回函数指针的函数, 返回的函数指针,形参列表为两个int, 返回值为int
/* int (*fun(int a, int b))(int, int) { */
FUNP fun(int a1, int b1) {
    printf("a1=%d\n", a1);
    printf("b1=%d\n", b1);
    return add;
}
