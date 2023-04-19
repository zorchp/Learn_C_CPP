#include <stdarg.h>
#include <stdio.h>

#define TEST(cond, ...) \
    ((cond) ? printf("Passed test: %s\n", #cond) : printf(__VA_ARGS__))

void t1() {
    int v = 10, maxV = 20;
    TEST(v <= maxV, "v %d exceeds %d\n", v, maxV);
    v = 100, maxV = 20;
    TEST(v <= maxV, "v %d exceeds %d\n", v, maxV);
    /*
    Passed test: v <= maxV
    v 100 exceeds 20
    */
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}