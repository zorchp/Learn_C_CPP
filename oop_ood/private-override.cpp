#include <bits/stdc++.h>
using namespace std;


class P {
private:
    virtual void f() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Q : public P {
public:
    void f() override { cout << __PRETTY_FUNCTION__ << endl; }
};

int main(int argc, char *argv[]) {
    P *p = new Q;
    p.f();
    return 0;
}
