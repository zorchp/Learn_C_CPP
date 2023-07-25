#include <bits/stdc++.h>
using namespace std;
/*
=default 只能用在五类特殊函数中
These special member functions are
the default constructor,
the copy constructor,
the copy assignment operator,
the move constructor,
the move assignment operator,
and the destructor.
=delete 可以用在任何函数上, =0只能用在虚函数上
*/

class Zoo {
public:
    Zoo(int i1, int i2) : d1(i1), d2(i2) {}
    Zoo(const Zoo&)             = delete;  // copy ctor
    Zoo(Zoo&&)                  = default; // rvalue refer
    Zoo& operator=(const Zoo&)  = default; // copy assign
    Zoo& operator=(const Zoo&&) = delete;  // move
    virtual ~Zoo() {}

private:
    int d1, d2;
};
void t1() {
    Zoo z1{1, 2};
    // Zoo z2(z1);// error: call to deleted constructor of 'Zoo'
    // Zoo z3 = z1;// error: call to deleted constructor of 'Zoo'
}

class Foo {
public:
    Foo(int i) : _i(i) {} // ctor with args
    Foo() = default;      // ctor without args

    Foo(const Foo& x) : _i(x._i) {} // copy ctor
    // Foo(const Foo&) = default;
    // Foo(const Foo&) = delete;

    Foo& operator=(const Foo& x) {
        _i = x._i;
        return *this;
    } // copy assign
    // Foo& operator=(const Foo& x) = default;
    // Foo& operator=(const Foo& x) = delete;

    // void fc1() = default; //error: only special member functions may be
    // defaulted
    void fc2() = delete;
    // virtual void fc3() = 0;

    // ~Foo() = delete;
    ~Foo() = default;

private:
    int _i;
};

void t2() {
    Foo f1(5);
    Foo f2;
    Foo f3(f1);
    f3 = f2;
}

class Empty {};
/*equal to

class Empty{};
class Empty{
public:
    Empty() {}
    Empty(const Empty& rhs){}
    ~Empty() {}

    Empty& operator=(const Empty& rhs){}
};
*/

void t3() {
    Empty e1;     // ctor without args
    Empty e2(e1); // copy ctor
    e2 = e1;      // copy assign
} // dtor


struct NoCopy { //禁用copy, 可用于单例模式
    NoCopy()                         = default;
    NoCopy(const NoCopy&)            = delete;
    NoCopy& operator=(const NoCopy&) = delete;
    ~NoCopy()                        = default;
};

struct NoDtor {
    NoDtor()  = default;
    ~NoDtor() = delete;
};

void t4() {
    // NoDtor nd;
    NoDtor* p = new NoDtor();
    // delete p;
}

class PrivateCopy { //可以通过友元访问, 例如boost::noncopyable, 可被继承,
                    //子类具有私有拷贝性质
private:
    PrivateCopy(const PrivateCopy&);
    PrivateCopy& operator=(const PrivateCopy&);

public:
    PrivateCopy() = default;
    ~PrivateCopy();
};


int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}