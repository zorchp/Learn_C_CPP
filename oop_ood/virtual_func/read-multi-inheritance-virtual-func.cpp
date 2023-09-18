#include <bits/stdc++.h>
using namespace std;

// 指针变量的大小
#if __WORDSIZE == 64
using TYPE = unsigned long long;
#else
using TYPE = int;
#endif

class B1 {
public:
    virtual void f1() { cout << "B1::f1()\n"; }
};
class B2 {
public:
    virtual void f1() { cout << "B2::f1()\n"; }
};
class B3 {
public:
    virtual void f1() { cout << "B3::f1()\n"; }
};

class C : public B1, public B2, public B3 {
public:
    virtual int f2() { return 1; }
    void f1() override final { cout << "C::f1()\n"; }
};

using FUNC = void (*)();
FUNC getvfunc(C *pa, int pos = 0, int offset = 0) {
    return *((FUNC *)(*(TYPE *)pa + offset) + pos);
}

void t1() {
    // 三个基类, 每个基类都含有虚指针, 所以结果是 24,
    // 为什么自己的虚指针没算在内???
    // cout << sizeof(C) << endl; // 24
    C c;
    // getvfunc(&c, 0)();
    // printf("%p\n", &C::f1);     // 0x0
    // printf("%p\n", &C::B1::f1); // 0x0
}

void t2() {
    B1 *pb1 = new C;
    TYPE vptr = *(TYPE *)pb1;
    TYPE pf = *(TYPE *)vptr;
    FUNC f1 = (FUNC)pf;
    f1();
}

int main(int argc, char *argv[]) {
    t1();
    // t2();

    return 0;
}
