#include <iostream>

namespace mylib {
struct S {};
void f(S) {
    std::cout << "f found by ADL\n";
}
} // namespace mylib

void f(mylib::S) {
    std::cout << "global f found by Usual Unqualified Lookup\n";
}

int main() {
    mylib::S s;
    // 这里存在两个定义，本应产生歧义，但当你给调用名称加个括号，就可以阻止ADL，从而消除歧义。
    (f)(s); // OK, calls global f
    // f(s);
    // error: call to 'f' is ambiguous
}
