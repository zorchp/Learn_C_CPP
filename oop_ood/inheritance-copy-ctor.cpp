#include <cstdio>
class B {
public:
    B() {
        printf("%s default-ctor\n", __func__);
    }
    B(const B &) {
        printf("%s copy-ctor\n", __func__);
    }
    B &operator=(const B &) {
        printf("%s\n", __func__);
        return *this;
    }
    ~B() {
        printf("%s\n", __func__);
    }
};

class D1 : public B {
public:
    // nothing
};

void t1() {
    D1 d0;     // B default-ctor
    D1 d1(d0); // B copy-ctor
    D1 d2;     // B default-ctor
    d2 = d0;   // operator=
    // ~B
    // ~B
    // ~B
}

class D2 : public B {
public:
    D2() {
        printf("%s default-ctor\n", __func__);
    }
    D2(const D2 &) {
        printf("%s copy-ctor\n", __func__);
    }
    D2 &operator=(const D2 &) {
        printf("%s D2 \n", __func__);
        return *this;
    }
    ~D2() {
        printf("%s\n", __func__);
    }
};

void t2() {
    // 先调用基类版本, 然后是子类版本
    D2 d0;
    // B default-ctor
    // D2 default-ctor
    D2 d1(d0);
    // B default-ctor
    // D2 copy-ctor
    D2 d2;
    // B default-ctor
    // D2 default-ctor
    d2 = d0;
    // operator= D2

    // ~D2
    // ~B
    // ~D2
    // ~B
    // ~D2
    // ~B
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
