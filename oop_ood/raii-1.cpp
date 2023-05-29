#include <bits/stdc++.h>

using namespace std;

class P {
public:
    P() { cout << "P::P()\n"; }
    ~P() { cout << "P::~P()\n"; }
};


void t1() {
    cout << "begin\n";
    {
        P p;
        cout << "process\n";
    }
    cout << "end\n";
    // 作用域结束, 直接调用析构函数, 所以可以通过这一特性设置智能指针
    // begin
    // P::P()
    // process
    // P::~P()
    // end
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
