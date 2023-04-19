#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    friend bool operator==(const Base &, const Base &);

public:
    // Base 接口成员
protected:
    virtual bool equal(const Base &) const;
};

bool operator==(const Base &lhs, const Base &rhs) {
    // 如果typeid不同, 返回False, 否则调用虚函数equal
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base &rhs) const { return 1; }

class Derived : public Base {
public:
    // Derived其它接口成员
protected:
    bool equal(const Base &) const;
};

bool Derived::equal(const Base &rhs) const {
    auto r = dynamic_cast<const Derived &>(rhs);
    //执行比较
}


void t1() {}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}