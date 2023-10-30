#include <iostream>
using namespace std;

class P {
public:
    virtual void f() { std::cout << "called f()\n"; }
};
int main(int argc, char *argv[]) {
    //
    using F = void (*)();
    auto p = new P;
    cout << hex;
    cout << "p addr=" << p << endl;
    auto vptr = *(long *)p;
    cout << "vptr=" << vptr << endl;
    auto vtbl = *(F *)vptr;
    cout << "vtbl=" << (long *)vtbl << endl;
    vtbl();
    delete p;
    return 0;
}
