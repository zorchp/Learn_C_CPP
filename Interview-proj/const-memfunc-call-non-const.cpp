#include <iostream>
using namespace std;


class P {
    mutable int x;

public:
    void f() const {
        x = 1;
        cout << "f\n";
        // g();
    }
    void g() {
        x = 1;
        cout << "g\n";
    }
};


int main(int argc, char *argv[]) {
    P p;
    p.f();

    return 0;
}
