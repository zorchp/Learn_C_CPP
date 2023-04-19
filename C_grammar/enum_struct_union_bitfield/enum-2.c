#include <stdio.h>

enum nu1 {
    a,
    b,
    c,
    d,
};

enum nu2 {
    e = 3,
    f = 2,
    g,
    h,
};

int main() {
    printf("枚举类型常量a的值为:%d   b的值为:%d   c的值为:%d   d的值为:%d\n", a,
           b, c, d);
    printf("枚举类型变量e的值为:%d   f的值为:%d   g的值为:%d   h的值为:%d\n", d,
           f, g, h);
    /*
    枚举类型常量a的值为:0   b的值为:1   c的值为:2   d的值为:3
    枚举类型变量e的值为:3   f的值为:2   g的值为:3   h的值为:4
    */
    return 0;
}
