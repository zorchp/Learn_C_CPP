#include <iostream>
using namespace std;

void t1() {
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    // int &r4 = r1 * 2; // r4是一个普通的非常量引用
}

void t11() {
    double d = 1.2;
    const int &r = d;
    /*
    const int tmp=d;
    const int& r=tmp;
    */
}

void t2() {
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    r1 = 0;
    // r2 = 0;//read-only-reference
}

int main(int argc, char const *argv[]) {
    // t1();
    // t11();
    t2();
    return 0;
}