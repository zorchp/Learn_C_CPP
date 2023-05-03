#include <stdio.h>
#include <stdlib.h>
void t1() {
    // #表示变量替换
#define AREA(x, y) \
    printf("长为" #x ",宽为" #y "的长方形面积为%d.\n", (x) * (y));

    int i = 55, j = 3;
    AREA(i, j);
    AREA(3, 2);
    /*
    长为i,宽为j的长方形面积为165.
    长为3,宽为2的长方形面积为6.
    */
}


//##表示连接
#define VAR(n) v##n

int v1(int a, int b) { return a + b; }
int v2(int a, int b) { return a - b; }
void t2() {
    printf("%d\n", VAR(1)(2, 3));
    printf("%d\n", VAR(2)(2, 3));
    /*
    5
    -1
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
