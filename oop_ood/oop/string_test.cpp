#include "string.h"

#include <iostream>

using namespace std;


void t1() {
    String s1("hello");
    String s2("world");

    String s3(s2);
    cout << s3 << endl;

    s3 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
    cout << sizeof(s3) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s1) << endl;
}

void t2() {
    String* p1 = new String("the first");
    p1 = new String("lalala");
    cout << sizeof(p1) << endl;
    cout << p1 << endl;
    cout << *p1 << endl;
    delete p1; // 只调用一次dtor
}

void t3() {
    String* p1 = new String[3]; // 调用三次析构
    p1[1] = String("the first");
    cout << sizeof(p1) << endl;
    cout << p1[1] << endl;
    cout << *p1 << endl;
    // delete p1;   // 只调用一次dtor
    delete[] p1; // 3次
}

int main() {
    // t1();
    // t2();
    t3();
}
