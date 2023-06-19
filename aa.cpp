#include <bits/stdc++.h>
#include <cassert>
#include <memory>
using namespace std;

class P {
public:
    int val;
};

void print(ostream &os, unique_ptr<P> &p) {
    os << p->val;
}

int main(int argc, char *argv[]) {
    //
    unique_ptr<P> a(new P);
    vector<unique_ptr<P>> vp;
    // vp.emplace_back(new P);
    // vp.emplace_back(a);
    vp.push_back(a);
    assert(a);

    return 0;
}
