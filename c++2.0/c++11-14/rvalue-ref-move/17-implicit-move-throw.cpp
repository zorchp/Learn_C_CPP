#include <iostream>
#include <string>

struct X {
    X() = default;
    X(const X &) = default;
    // X(const X &x) { std::cout << "copy-ctor\n"; }
    X(X &&) { std::cout << "move\n"; }
};


void f() {
    X x;
    throw x;
}
int main() {
    try {
        f();
    } catch (...) {}
}