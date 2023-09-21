#include <bits/stdc++.h>
using namespace std;
class B {
public:
    void f() { std::cout << "f\n"; }
    static int x;
    string y;

protected:
    void g() { cout << "g\n"; }
};

class D : public B {
public:
    void h() {
        g();
        cout << "h\n";
    }
};


int main(int argc, char *argv[]) {
    D d;
    d.f();
    cout << d.x;
    cout << d.y;
    // d.g();
    return 0;
}
