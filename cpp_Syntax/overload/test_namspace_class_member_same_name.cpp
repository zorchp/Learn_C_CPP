// Example from ISO C++
#include <typeinfo>
#include <iostream>

namespace A {
// int x;
struct x {};
int y;
} // namespace A

namespace B {
struct y {};
} // namespace B

namespace C {
using namespace A;
using namespace B;
// int i = C::x; // #1
// auto i = C::x; // #1

// A::x i = C::x; // #1
// error: no type named 'x' in namespace 'A'

// A::x i = C::x(); // #1
A::x i = C::x{}; // #1


// ambiguous
//  int j = C::y; // #2

} // namespace C

void t1() {
    using namespace C;
    std::cout << typeid(i).name(); // i
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
