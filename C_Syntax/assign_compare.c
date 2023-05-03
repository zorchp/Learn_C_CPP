#include <stdio.h>
#include <stdlib.h>


void test1() {
    int a = 1;
    if (a = 4) // 不判断直接进入if结构体
        printf("a=1\n");
}

void t2() {
    int b = 3;
    if (b = 2 < 3) {
        printf("b=%d\n", b);
        printf("b=%d\n", 2 < 3);
    }
}

int main(int argc, char const *argv[]) {
    // test1();
    t2();
    return 0;
}
