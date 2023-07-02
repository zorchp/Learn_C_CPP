#include <cstdio>
#include <algorithm>


void t1() {
    unsigned x = 11;
    // definition in countl.h
#ifdef __clang__
    printf("clz of %d is %d\n", x, std::__libcpp_clz(x));
    printf("lg2i of %d is %d\n", x, std::__log2i(x));
    printf("countl of %d is %d\n", x, std::__countl_zero(x));
    printf("ctz of %d is %d\n", x, std::__libcpp_ctz(x));
#endif
    // clz of 11 is 28
    // lg2i of 11 is 3
    // countl of 11 is 28
    // ctz of 11 is 0
#ifdef __GNUG__
#ifndef __clang__
    printf("lg of %d is %d\n", x, std::__lg(x)); // 3
#endif
#endif
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
