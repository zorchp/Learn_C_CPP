#include <stdio.h>
int main() {
    int a = 0, b = 0, c = 0, d = 0;
    scanf("%d", &a);           // 输入整数并赋值给变量a
    scanf("%d", &b);           // 输入整数并赋值给变量b
    printf("a+b=%d\n", a + b); // 计算a+b的值并输出
    scanf("%d %d", &c, &d);    // 输入两个整数并分别赋值给c、d
    printf("c*d=%d\n", c*d);  //计算c*d的值并输出

    return 0;
}