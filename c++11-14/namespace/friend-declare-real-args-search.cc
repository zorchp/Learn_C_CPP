#include <iostream>

using namespace std;

namespace A {
class C {
    friend void f2() {}
    friend void f(const C &) {}
};
} // namespace A

int main(int argc, char const *argv[]) {
    A::C cobj;
    f(cobj); //正确,根据实参相关的查找规则可以被找到
    // f2();    //找不到

    return 0;
}