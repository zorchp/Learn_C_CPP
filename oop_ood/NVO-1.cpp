#include <iostream>
using namespace std;

class P {
    [[maybe_unused]] int x;

public:
    P() { cout << __PRETTY_FUNCTION__ << endl; }
    ~P() { cout << __PRETTY_FUNCTION__ << endl; }
    P(const P&) { cout << __PRETTY_FUNCTION__ << endl; }
    P& operator=(const P&) {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }
    P(P&&) { cout << __PRETTY_FUNCTION__ << endl; }
    P& operator=(P&&) {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }
};

P f() { // return value
    P p{};
    [[maybe_unused]] P q{};
    // return p; // NRVO:1
    // return 1 ? p : q; // no NRVO:2
    if (1) {
        return p; // case 3: NRVO
    } else {
        return q;
    }
}

void t1() {
    auto x [[maybe_unused]] = f();
    // case 1:
    //  ==> clang++ NVO-1.cpp -fno-elide-constructors && ./a.out
    //  P::P()
    //  P::P()
    //  P::P(P &&)
    //  P::~P()
    //  P::~P()
    //  P::~P()

    // case 2:
    // ==> clang++ NVO-1.cpp -fno-elide-constructors && ./a.out
    // P::P()
    // P::P()
    // P::P(const P &)
    // P::~P()
    // P::~P()
    // P::~P()

    // case 3:
    // ==> clang++ NVO-1.cpp -fno-elide-constructors && ./a.out
    // P::P()
    // P::P()
    // P::P(P &&)
    // P::~P()
    // P::~P()
    // P::~P()

    /// NRVO 事实上等价于调用 move-ctor
}

int main(int argc, char* argv[]) {
    t1();
    return 0;
}
