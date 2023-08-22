#include <cstdio>

template <int n>
struct factorial {
    static_assert(n >= 0, "arg must be non-negative");
    static const int val = n * factorial<n - 1>::val;
};

template <>
struct factorial<0> {
    static const int val = 1;
};

int main(int argc, char *argv[]) {
    printf("%d\n", factorial<10>::val);
    return 0;
}
