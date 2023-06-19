#include <cstdio>
#include <memory> //std::move
class B {
public:
    B() {
        printf("%s default-ctor\n", __func__);
    }
    B(B &&) {
        printf("%s B&&\n", __func__);
    }
    B &operator=(B &&) {
        printf("%s B&&\n", __func__);
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
    D1 d0;                // B default-ctor
    D1 d1(std::move(d0)); // B B&&
    D1 d2;                // B default-ctor
    d2 = std::move(d0);   // operator= B&&
    // ~B
    // ~B
    // ~B
}

class D2 : public B {
public:
    D2() {
        printf("%s default-ctor\n", __func__);
    }
    D2(D2 &&) {
        printf("%s D2&&\n", __func__);
    }
    D2 &operator=(D2 &&) {
        printf("%s D2&&\n", __func__);
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
    D2 d1(std::move(d0));
    // B default-ctor
    // D2 D2&&
    D2 d2;
    // B default-ctor
    // D2 default-ctor
    d2 = std::move(d0);
    // operator= D2&&

    // ~D2
    // ~B
    // ~D2
    // ~B
    // ~D2
    // ~B

    // call copy
    // D2 d3(d0); // implicitly-deleted
    // D2 d4;
    // d4 = d1;
}

class D3 : public B {
public:
    D3() {
        printf("%s default-ctor\n", __func__);
    }
    D3(const D3 &) {
        printf("%s copy-ctor\n", __func__);
    }
    D3 &operator=(const D3 &) {
        printf("%s D3 \n", __func__);
        return *this;
    }
    ~D3() {
        printf("%s\n", __func__);
    }
};

void t3() { // 类没有声明移动构造函数和移动赋值运算符, 则使用 copy 版本
    // 自定义 copy 版本之后编译器不会生成默认的 move 版本
    D3 d0;
    // B default-ctor
    // D3 default-ctor
    D3 d1(std::move(d0));
    // B default-ctor
    // D3 copy-ctor
    D3 d2;
    // B default-ctor
    // D3 default-ctor
    d2 = std::move(d0);
    // operator= D3
}


int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
