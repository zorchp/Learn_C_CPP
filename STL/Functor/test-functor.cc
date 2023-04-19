#include <bits/stdc++.h>
using namespace std;

class F {
public:
    virtual double operator()(double x) const = 0;
};
class Fun : public F {
public:
    double operator()(double x) const { return log(1.0 + x) / (1.0 + x * x); }
};
int main() {
    Fun f;
    cout << f(0) << endl; // 0
}