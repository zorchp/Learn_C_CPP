#include <strings.h> //ffs
#include <cstdio>
#include <algorithm> // __lg

int my__lg(int x) {
    int ans{};
    for (; x; x >>= 1) ++ans;
    return ans - 1;
}

void t1() {
    int x = 11;             // 0b1011
    printf("%d\n", ffs(x)); // 1
    printf("%d\n", ffs(0)); // 1
#ifndef __clang__
    printf("in gnu c++:\n");
    printf("%d\n", std::__lg(x)); // 3
#endif
    printf("%d\n", my__lg(x));             // 3
    printf("%d\n", __builtin_popcount(x)); // 3
    // 返回 1 加上 x 的最低有效 1 位的索引
    printf("%d\n", __builtin_ffs(x)); // 1
    printf("%d\n", __builtin_clz(x)); // 28
    printf("%d\n", __builtin_ctz(x)); // 0
}

int main(int argc, char* argv[]) {
    t1();

    return 0;
}
