#include <bits/stdc++.h>
using namespace std;

void swap1(int *p, int *q) { // X
    int tmp = *p;            // p指向的值
    p = q;                   // p指向了q指向的数据
    *q = tmp;                // q指向了p指向的数据
    // 此时 p, q 同时指向p指向的值了
}

void swap2(int *p, int *q) { // X
    // cout << p << " " << q << endl;
    int *tmp = p; // tmp和p都指向p所指向的数据
    p = q;        // p指向q指向的数据
    q = tmp;      // q指向p指向的数据
    // cout << p << " " << q << endl;
    // 只有指针的指向发生改变了, 数据实际上没发生变化
}

void swap3(int *p, int *q) { // ok
    int tmp = *p;            // tmp存p指向的数据
    *p = *q;                 // p指向的数据变成q指向的数据
    *q = tmp;                // q指向的数据变成p之前指向的数据
}

void swap4(int *p, int *q) { // X
    int *tmp = p;            // tmp和p都指向p指向的数据
    *p = *q;                 // p指向的数据变成q指向的数据
    q = tmp;// q指向tmp指向的数据(p指向的数据)
    // 此时p, q 同时指向q指向的数据了
}


int main() {
    //
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    int *r = &a, *s = &b;
    swap4(r, s);
    cout << a << " " << b << endl;
}
