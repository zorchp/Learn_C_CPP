#include <stdio.h>

void t1() {
    int i = 100;
    printf("i=%d\n", i);

    for (int i = 0; i < 10; ++i) printf("%d ", i);
    putchar('\n');
    printf("i=%d\n", i);
}

void t2() {
    for (int i = 0; i < 10; ++i) {
        i = 9;
        // i = 8;
        printf("i=%d\n", i);
    }
}

void t3() {
    for (int i = 0; i != 0; ++i) { // 不执行, 说明初始化变量之后, 会执行条件判断
        printf("%d\n", i);
    }
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
