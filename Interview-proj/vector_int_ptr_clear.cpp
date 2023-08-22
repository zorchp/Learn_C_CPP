#include <bits/stdc++.h>
using namespace std;

void t1() {
    vector<int *> vp;
    for (int i{}; i < 10; ++i) {
        int *pa = new int(1);
        cout << pa << endl;
        vp.emplace_back(pa);
    }
    vp.clear();
    cout << vp[0]; // ok, gcc
}

void t2() {
    vector<int> v(10, 2);
    v.clear(); // 不影响
    for (int i{}; i < 10; ++i) cout << v[i];
    vector<int> vv;
    v.swap(vv); // must create temp obj, as lvalue
    // segment fault
    for (int i{}; i < 10; ++i) cout << v[i];
}

class P {
public:
    P() : x(1), y(2.9) { cout << "P\n"; }
    ~P() { cout << "~P\n"; }
    int x;
    double y;
};
void t3() {
    int n = 5;
    vector<P *> v(n);
    for (int i{}; i < n; ++i) {
        auto tmp = new P;
        cout << tmp << endl;
        v[i] = tmp;
    }
    v.clear();
    for (int i{}; i < n; ++i) {
        cout << v[i]->x << endl;
    }
}
int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();

    return 0;
}
