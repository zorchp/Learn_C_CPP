#include <iostream>

struct X {
    X() = default;
    X(const X &) = default;
    X(X &&) { std::cout << "move ctor\n"; } //隐式使用move-ctor
};

X f1(X x) { return x; }

void t1() { X r = f1(X{}); }

X f2() {
    X x;
    return x;
}

void t2() { X r = f2(); }

X f3(X &&x) { return x; }

void t3() { X r = f3(X()); }

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}