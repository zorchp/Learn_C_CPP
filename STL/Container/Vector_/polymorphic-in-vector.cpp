#include <iostream>
#include <vector>
using namespace std;

class B {
    int x;

public:
    B(int y = 0) : x(y) {}
    operator int() { return x; }
    virtual void f() { cout << __PRETTY_FUNCTION__ << endl; }
    virtual ~B() {}
};

class D : public B {
public:
    void f() override { cout << __PRETTY_FUNCTION__ << endl; }
};

void t1() {
    vector<B *> vpb;
    B b;
    vpb.emplace_back(&b);
    D d;
    vpb.emplace_back(&d);
    auto pd = new D();
    vpb.emplace_back(pd);
    vpb[0]->f();
    vpb[1]->f();
    vpb[2]->f();
} // 多态: ok

void t2() {
    vector<B> vb;
    vb.emplace_back(10);
    vb.emplace_back(D());
    vb[0].f();
    vb[1].f(); // 不是多态调用
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
