#include <iostream>
#include <string>
using namespace std;

void t1() {
    string* ps = new string;
    cout << "strs: " << *ps << endl;
    // ps->string::string("1");//error,不能直接调用, 但是编译器可以
    // error: 'class std::__cxx11::basic_string<char>' has no member named
    // 'string'
    // ps->string::~string;
}
class A {
public:
    int id;
    A(int i) : id(i) { cout << "ctor. this=" << this << ' ' << id << endl; }
    ~A() { cout << "dtor. this=" << this << endl; }
};

void t2() {
    A* pA = new A(1);
    // vc can build successfully
    // pA->A::A(3); // error: cannot call constructor 'A::A' directly
    delete pA;
    // ctor. this=0x600001d14040 1
    // dtor. this=0x600001d14040
}

void t3() {
    // 采用placement new 调用构造函数
    A* pA = new A(1);
    new (pA) A(2);
    // ctor. this=0x600000578040 1
    // ctor. this=0x600000578040 2
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    // t3();
    return 0;
}
