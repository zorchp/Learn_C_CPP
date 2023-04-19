#include <stdio.h>

void t1() {
    int a = 10;
    // test();
    extern void test();
    test();
    int x = 10;
    printf("a=%d, x=%d\n", a, x);
}
void test() { printf("test\n"); }
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}