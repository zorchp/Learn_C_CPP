#include <iostream>

namespace X {
template <typename T>
void f(T);
}

namespace N {
using namespace X;

enum E { e1 };

void f(E) { std::cout << "N::f(N::E) called\n"; }
} // namespace N

void f(int) { std::cout << "::f(int) caled\n"; }

int main() {
    ::f(N::e1); // qualified function name : not use ADL
    f(N::e1);   // use ADL, will find N::f()
}
