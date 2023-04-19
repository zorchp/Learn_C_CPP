#include <iostream>
using namespace std;

class P {
public:
    P() {
        new (this) P(1, 1.2);
        cout << "call P()\n";
    }
    P(int a) {
        new (this) P(a, 1.2);
        cout << "call P(int)\n";
    }
    // 使用委托构造
    //  P() : P(1, 1.2) { cout << "call P()\n"; }
    //  P(int a) : P(a, 1.2) { cout << "call P(int)\n"; }

private:
    // target ctor
    P(int a, double b) : m_a(a), m_b(b) { cout << "call P(int, double)\n"; }

    int m_a;
    double m_b;
};

void t1() {
    // 使用placement new
    P p1;
    // call P(int, double)
    // call P()

    P p2(10);
    // call P(int, double)
    // call P(int)
}

void t2() {
    // C++11: 使用委托构造
    P p1;
    // call P(int, double)
    // call P()

    P p2(10);
    // call P(int, double)
    // call P(int)
}

int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}
