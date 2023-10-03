#include <memory>
#include <iostream>
using namespace std;
class P {
public:
    P() {}
    void f() { cout << "f\n"; }
};

void t1() {
    auto up = make_unique<P>();
    up->f();
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}