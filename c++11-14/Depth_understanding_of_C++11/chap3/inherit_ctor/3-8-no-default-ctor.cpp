#include <iostream>
using namespace std;


struct A {
    A(int) { cout << "use A::A(int)\n"; }
};

struct B : A {
    using A::A;
};


int main(int argc, char *argv[]) {
    /* B b1;    // error */
    B b2(1); // use A::A(int)

    return 0;
}
