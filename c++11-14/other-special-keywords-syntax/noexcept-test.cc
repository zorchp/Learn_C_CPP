#include <bits/stdc++.h>
using namespace std;

// void foo() noexcept;
// void foo () noexcept(true);

void test() {
    range_error r("error");
    throw r;
}


void foo() {
    cout << typeid(main).name() << endl;
    cout << typeid(test).name() << endl;
    cout << typeid(test()).name() << endl;
    cout << typeid(noexcept(test())).name() << endl;
    cout << noexcept(test());
}

void t1() { foo(); }

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
