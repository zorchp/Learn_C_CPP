#include <iostream>
using namespace std;

struct A {
    char c;
    int x;
    short s;
};

struct B {
    int x;
    char c;
    short z;
};

struct C {
    char c;
    short s;
    int x;
};

void t1() {
    cout << sizeof(A) << endl; // 12
    cout << sizeof(B) << endl; // 8
    cout << sizeof(C) << endl; // 8
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
