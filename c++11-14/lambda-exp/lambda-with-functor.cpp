#include <bits/stdc++.h>
using namespace std;

class UnNameLocalFunction {
private:
    int local;

public:
    UnNameLocalFunction(int val) : local(val) {}
    bool operator()(int val) { return val == local; }
};

void t1() {
    int t   = 5;
    auto l1 = [t](int val) { return val == t; };
    UnNameLocalFunction l2(t);
    bool b1 = l1(5);
    bool b2 = l2(5);
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}