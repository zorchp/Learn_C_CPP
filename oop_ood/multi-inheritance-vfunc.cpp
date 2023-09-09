#include <ctime>
#include <iostream>
using namespace std;

namespace multi_inherit {
class B1 {
public:
    B1() { cout << "B1()\n"; }
    virtual ~B1() { cout << "~B1()\n"; }
};
class B2 {
public:
    B2() { cout << "B2()\n"; }
    virtual ~B2() { cout << "~B2()\n"; }
};
class B3 {
public:
    B3() { cout << "B3()\n"; }
    virtual ~B3() { cout << "~B3()\n"; }
};

class C : public B1, public B2, public B3 {
public:
    C() { cout << "C()\n"; }
};
} // namespace multi_inherit


namespace multi_inherit_with_virtual_base_class {
class B1 {
public:
    B1() { cout << "B1()\n"; }
    ~B1() { cout << "~B1()\n"; }
};
class B2 {
public:
    B2() { cout << "B2()\n"; }
    ~B2() { cout << "~B2()\n"; }
};
class B3 {
public:
    B3() { cout << "B3()\n"; }
    virtual ~B3() { cout << "~B3()\n"; }
};

class C : virtual public B1, virtual public B2, virtual public B3 {
public:
    C() { cout << "C()\n"; }
};
} // namespace multi_inherit_with_virtual_base_class


void t1() {
    using namespace multi_inherit;
    B1 b;
    C c;
    // cout << sizeof(b) << endl;  // 8
    // cout << sizeof(c) << endl;  // 24
    cout << sizeof(B1) << endl; // 8
    cout << sizeof(B2) << endl;
    cout << sizeof(B3) << endl;
    cout << sizeof(C) << endl; // 24
}
void t2() {
    using namespace multi_inherit_with_virtual_base_class;
    cout << sizeof(B1) << endl; // 8
    cout << sizeof(B2) << endl;
    cout << sizeof(B3) << endl;
    cout << sizeof(C) << endl; // 24
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
