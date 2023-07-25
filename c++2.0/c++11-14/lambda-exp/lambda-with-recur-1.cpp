#include <iostream>

void t1() { // use curry(Y-combinator)
    auto T = [&](auto x) {
        return [&](auto y) { return y([&](auto z) { return x(x)(y)(z); }); };
    };
    auto X = T(T);
    auto fib = X([](auto f) {
        return [&](auto n) -> int { return n < 2 ? n : f(n - 1) + f(n - 2); };
    });
    std::cout << fib(6);
}

void t2() { // use auto (c++17), call self
    auto fib = [](auto&& self, int n) -> int {
        return n > 1 ? self(self, n - 1) + self(self, n - 2) : n;
    };
    std::cout << fib(fib, 6);
}

void t3() {
    auto f = [](auto&& self, int n, int i = 0, int num1 = 0, int num2 = 1) {
        if (i >= n)
            return num1;
        else
            return self(self, n, i + 1, num2, num1 + num2);
    };
    auto fib = [&f](int n) { return f(f, n); };
    std::cout << fib(6);
}
int main() {
    // t1();
    // t2();
    t3();
    return 0;
}