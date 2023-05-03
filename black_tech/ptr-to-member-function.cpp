#include <iostream>

struct C {
    void f(int n) { std::cout << n << '\n'; }
};

int main() {
    void (C::*p)(int) = &C::f; // pointer to member function f of class C
    C c;
    (c.*p)(1);                 // prints 1
    C* cp = &c;
    (cp->*p)(2);               // prints 2
}