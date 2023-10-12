#include <bits/stdc++.h>
using namespace std;

namespace base_test {
class A {
public:
    int x = 10;

    void f1() { printf("%d\n", x); }
    void f2() { printf("%p\n", &x); }
    void f3() { printf("hello\n"); }
};
} // namespace base_test

namespace static_test {
class A {
public:
    int x = 10;

    static void f1() { printf("%d\n", x); }
    static void f2() { printf("%p\n", &x); }
    static void f3() { printf("hello\n"); }
};
} // namespace static_test

namespace virtual_test {
class A {
public:
    int x = 10;

    virtual void f1() { printf("%d\n", x); }
    void f2() { printf("%p\n", &x); }
    // virtual void f2() { printf("%p\n", &x); }
    virtual void f3() { printf("hello\n"); }
};
} // namespace virtual_test

void t1() {
    // using namespace base_test;
    using namespace static_test;
    // using namespace virtual_test;
    A* a = nullptr;
    a->f1();
    a->f2();
    a->f3();
}

int main(int argc, char const* argv[]) {
    //
    t1();
    return 0;
}
