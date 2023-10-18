#include <iostream>

using namespace std;

#define align


struct
#ifdef align
    alignas(2)
#endif
        p {
    short y;
    char z;
};

void t0() {
    cout << alignof(p) << endl; // 2
    cout << sizeof(p) << endl;  // 4
}

void t1() {
    cout << alignof(char) << endl;  // 1
    cout << alignof(short) << endl; // 2
    cout << alignof(int) << endl;   // 4
}

void t2() {
    typedef struct {
        int a;    // 4
        double b; // 8
    } S;
    cout << alignof(S) << endl; // 8, max size of S
    cout << sizeof(S) << endl;  // 16
}

int main() {
    t0();
    // t1();
    // t2();
}
