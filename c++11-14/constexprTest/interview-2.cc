#include <iostream>

struct Foo {
    static constexpr int x = 42;
};

int f(const int& r) {
    std::cout << r << std::endl;
    return 0;
}

int main() {
    std::cout << Foo::x << std::endl;
    int array[Foo::x] = {0};
    const int& x = Foo::x;
    std::cout << x << std::endl;
    int a;
    std::cin >> a;
    int n = a ? Foo::x : f(Foo::x);
    std::cout << n << ", " << array[0] << std::endl;
}
