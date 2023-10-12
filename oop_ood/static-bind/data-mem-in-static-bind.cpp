#include <iostream>
using namespace std;

class P {
public:
    int x;
    void f() { cout << __PRETTY_FUNCTION__ << '\n'; }
    void g() { cout << x << '\n'; }
};

int main(int argc, char *argv[]) {
    P *p = nullptr;
    p->f(); // ok
    p->g(); // runtime error
    return 0;
}
