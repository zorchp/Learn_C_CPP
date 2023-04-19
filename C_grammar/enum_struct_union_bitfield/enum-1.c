#include <stdio.h>

void t1() {
    enum E { mon = 1, tue, wed } e1, e2 = 10;
    printf("%d\n", mon);
    printf("%d\n", tue);
    printf("%d\n", wed);
    printf("%d\n", e1);
    printf("%d\n", e2);
    /*
    1
    2
    3
    1
    10
    */
}

void t2() {
    enum { a, b, c };
    printf("%d\n", a); // 0
    printf("%d\n", b); // 1
    printf("%d\n", c); // 2
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
