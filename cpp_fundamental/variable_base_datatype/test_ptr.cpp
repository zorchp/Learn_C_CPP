#include <iostream>
using namespace std;

void test1() {
    int i   = 42;
    int *pi = &i;
    *pi     = *pi * *pi;
    int *pj = pi;
    cout << *pi << endl;
    cout << *pj << endl;
    cout << i << endl;
}

void test2() {
    int i = 0;
    // double* dp = &i;
    // int *ip = i;
    int *p = &i;
}


void test3() {
    int i = 10, *p = &i;
    if (p)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    if (*p)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

int main(int argc, char const *argv[]) {
    // test1();
    // test2();
    test3();
    return 0;
}
