#include <bits/stdc++.h>
using namespace std;


void t1() {
    int x  = 0;
    int* p = &x; //取地址传给指针
    // printf("%lu\n", sizeof(p));//8
    int& r = x;              // r代表x, r=x=0
    printf("%d,%d\n", r, x); // 0,0

    // printf("%lu,%lu\n", sizeof(r), sizeof(x));//4,4
    int x2 = 5;
    r      = x2;
    printf("%d,%d\n", r, x); // 5,5

    int& r2 = r;
    printf("%d,%d\n", r2, x); // 5,5
}


void t2() {
    double x  = 0;
    double* p = &x;
    double& r = x;
    cout << sizeof(x) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(r) << endl; //假象: sizeof(x)=sizeof(r),x=r,&r=&x
    cout << p << endl;
    cout << *p << endl;
    cout << x << endl;
    cout << r << endl;
    cout << &x << endl;
    cout << &r << endl;
    /*
    8
    8
    8
    0x16cf37488
    0
    0
    0
    0x16cf37488
    0x16cf37488
    */
}

typedef struct Stag {
    int a, b, c{}, d;
} S;
ostream& operator<<(ostream& os, const Stag& s) {
    cout << s.a << " " << s.b << " " << s.c << " " << s.d << " ";
    return os;
}
void t3() {
    S s;
    S& rs = s;
    cout << sizeof(s) << endl;
    cout << sizeof(rs) << endl;
    cout << s << endl;
    cout << rs << endl;
    cout << &s << endl;
    cout << &rs << endl;
    /*
    16
    16
    0 0 0 1
    0 0 0 1
    0x16b3e7480
    0x16b3e7480
    */
}
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
