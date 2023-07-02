#include <iostream>


namespace rule1 {

// 第一点，当实参类型为函数时，ADL会根据该函数的参数及返回值所属作用域进行查找。
namespace B {
struct R {};
void g(...) { // arbitrary argse
    std::cout << "g found by ADL\n";
}
} // namespace B

namespace A {
struct S {};
// 通过这里的类型定义找到了作用域 B
typedef B::R (*pf)(S); // 参数为 S 类型, 返回值为 B::R 类型的函数指针

void f(pf) {
    std::cout << "f found by ADL\n";
}
} // namespace A

B::R bar(A::S) {
    return {};
}
} // namespace rule1

void t1() {
    using namespace rule1;
    A::pf fun = bar;
    f(fun); // #1, OK
    g(fun); // #2, OK
}

namespace rule2 {

// 第二点，若实参类型是一个类，那么ADL会从该类或其父类的最内层命名空间进行查找。
namespace A {
// S2
// void f(...) {
// }
struct Base {};
} // namespace A

namespace M {
// S3 not works!
// void f(...) {
// }
namespace B {
// S1
void f(...) {
}
struct Derived : A::Base {};
} // namespace B
} // namespace M
} // namespace rule2


void t2() {
    using namespace rule2;
    M::B::Derived d;
    f(d); // #1
}

namespace rule3 {
// 第三点，若实参类型是一个类模板，那么ADL会在特化类的模板参数类型的命名空间下进行查找；若实参类型包含模板模板参数，那么ADL还会在模板模板参数类型的命名空间下查找。
namespace C {
struct Final {};
void g(...) {
    std::cout << "g found by ADL\n";
}
}; // namespace C

namespace B {
template <typename T>
struct Temtem {};

struct Bar {};
void f(...) {
    std::cout << "f found by ADL\n";
}
} // namespace B

namespace A {
template <typename T>
struct Foo {};
} // namespace A

} // namespace rule3

void t3() {
    using namespace rule3;
    // class template arguments
    A::Foo<B::Bar> foo;
    f(foo); // OK

    // template template arguments
    A::Foo<B::Temtem<C::Final>> a;
    g(a); // OK
}

namespace rule4 {
// 第四点，当使用别名时，ADL会无效，因为名称并不是一个函数调用。
typedef int f;
namespace N {
struct A {
    friend void f(A &);
    operator int();
    void g(A a) {
        int i = f(a); // #1
    }
};
} // namespace N
} // namespace rule4

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
