#include <cstdio>
#include <iostream>

using namespace std;

namespace case_1 {
class Foo {
public:
    //
    Foo() { printf("%s\n", __func__); }
};

class Bar {
public:
    // 生成默认构造
    Foo foo;   // 将 Bar::foo 初始化是编译器的责任
    char *str; // str初始化要让程序员来做
};
// 可能的实现
// inline Bar::Bar() { foo.Foo::Foo(); }
} // namespace case_1
void t1() {
    using namespace case_1;
    Bar bar;
    // Foo
}

namespace case_1_1 {
class Foo {
public:
    //
    Foo() { printf("%s\n", __func__); }
};
class Foo1 {
public:
    //
    Foo1() { printf("%s\n", __func__); }
};

class Bar {
public:
    Bar() { str = 0; } // 如果已经有了只初始化str 的构造函数
    Foo foo;
    Foo1 foo1;
    char *str;
};
// 编译器规则:
// 如果类 A 含有一个及以上成员类对象, 那么 A 的每一个 ctor
// 都要调用每一个成员类的默认 ctor
} // namespace case_1_1

void t11() {
    using namespace case_1_1;
    Bar bar;
    // Foo
    // Foo1
}

namespace case_2 { // 带有 默认构造的基类
class A {
public:
    A() { printf("%s\n", __func__); }
};

class B : public A {
    // no default ctor
};

} // namespace case_2

void t2() {
    using namespace case_2;
    B b; // A
}

namespace case_3 { // 带有虚函数的类

class W {
public:
    virtual void flip() const = 0;
    W() { printf("%s\n", __func__); }
};
class Bell : public W {
    void flip() const {}
};
class Whistle : public W {
    void flip() const {}
};

void flip(const W &w) { w.flip(); }

} // namespace case_3

void t3() {
    using namespace case_3;
    Bell b;
    Whistle w;
    flip(b);
    flip(w);
    // W
    // W
}

namespace case_4 {
// 虚继承
class X {
public:
    int i;
};
class A : public virtual X {
public:
    int j;
};
class B : public virtual X {
public:
    int d;
};
class C : public A, public B {
public:
    int k;
};
void foo(A *pa) { pa->i = 1024; }
} // namespace case_4

void t4() {
    using namespace case_4;
    A *pa = new C;
    C *pc = new C;
    foo(pa);
    foo(pc);
    cout << pa->i << endl; // 1024
    cout << pc->i << endl; // 1024
}
int main(int argc, char *argv[]) {
    // t1();
    // t11();
    t2();
    // t3();
    // t4();
    return 0;
}
