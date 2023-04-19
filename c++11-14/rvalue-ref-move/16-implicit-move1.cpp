#include <iostream>
#include <string>

struct X {
    X() = default;
    X(const X &) = default;
    // X(const X &x) { std::cout << "copy-ctor\n"; }
    X(X &&) { std::cout << "move\n"; }
};

X f(X &&x) { return (x); }
// X f(X &&x) { return std::move(x); }

int main() { X r = f(X()); } // no move-ctor