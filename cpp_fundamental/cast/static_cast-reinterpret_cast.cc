#include <iostream>
using namespace std;

void test_static() {
    int* a  = new int(1);
    void* b = static_cast<void*>(a);
    int* c  = static_cast<int*>(b);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

void test_reinterpret() {
    int* a  = new int(2);
    void* b = reinterpret_cast<void*>(a);
    int* c  = reinterpret_cast<int*>(b);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
void t1() {
    test_static();
    test_reinterpret();
    /*
    0x600000b8c040
    0x600000b8c040
    0x600000b8c040
    0x600000b8c050
    0x600000b8c050
    0x600000b8c050
    */
}

struct B {};
struct D : B {
    B b;
};
void t2() {
    D d;
    B& br1 = d;
    B& br2 = d.b;

    static_cast<D&>(br1); // OK: lvalue denoting the original d object
    static_cast<D&>(br2); // UB: the b subobject is not a base class subobject
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
