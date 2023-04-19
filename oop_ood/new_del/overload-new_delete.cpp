#include <bits/stdc++.h>
using namespace std;


class Foo {
public:
    int _id;
    long _data;
    string _str;

public:
    Foo() : _id(0) {
        cout << "default ctor.this=" << this << " id=" << _id << endl;
    }
    Foo(int i) : _id(i) {
        cout << "ctor.this=" << this << " id=" << _id << endl;
    }

    // virtual or not
    ~Foo() { cout << "dtor.this=" << this << " id=" << _id << endl; }
    // virtual ~Foo() {cout << "dtor.this=" << this << " id=" << _id << endl;}

    static void* operator new(size_t size);
    static void operator delete(void* pdead, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead, size_t size);
};

void* Foo::operator new(size_t size) {
    Foo* p = (Foo*) malloc(size);
    cout << "Foo::new" << endl;
    return p;
}

void Foo::operator delete(void* pdead, size_t size) {
    cout << "Foo::delete" << endl;
    free(pdead);
}

void* Foo::operator new[](size_t size) {
    Foo* p = (Foo*) malloc(size);
    cout << "Foo::new[]" << endl;
    return p;
}

void Foo::operator delete[](void* pdead, size_t size) {
    cout << "Foo::delete[]" << endl;
    free(pdead);
}


void t1() {
    Foo* pf = new Foo;
    delete pf;

    Foo* pf1 = ::new Foo;
    ::delete pf1;
    /*
    Foo::new
    default ctor.this=0x6000003c8270 id=0
    dtor.this=0x6000003c8270 id=0
    Foo::delete
    default ctor.this=0x6000003c8270 id=0
    dtor.this=0x6000003c8270 id=0
    */

    // if not overload new and delete: call system new and delete
    /*
    default ctor.this=0x60000141c270 id=0
    dtor.this=0x60000141c270 id=0
    default ctor.this=0x60000141c270 id=0
    dtor.this=0x60000141c270 id=0
    */
}

void t2() {
    cout << "sizeof(int)=" << sizeof(int) << endl;
    cout << "sizeof(long)=" << sizeof(long) << endl;
    cout << "sizeof(string)=" << sizeof(string) << endl;
    cout << "sizeof(Foo)=" << sizeof(Foo) << endl;
    /*clang++
    sizeof(int)=4
    sizeof(long)=8
    sizeof(string)=24
    sizeof(Foo)=40
    */
    /*g++
    sizeof(int)=4
    sizeof(long)=8
    sizeof(string)=32
    sizeof(Foo)=48
    */
}

void t3() {
    cout << "sizeof(Foo)=" << sizeof(Foo) << endl; // g++: 48
    Foo* p = new Foo(7);
    cout << "sizeof(new Foo)=" << sizeof(*p) << endl;
    delete p;

    Foo* pArr = new Foo[5];
    cout << "sizeof(new Foo[5])=" << sizeof(*pArr) << endl;
    delete[] pArr;
    /*
    sizeof(Foo)=48
    Foo::new
    ctor.this=0x600000cfc270 id=7
    dtor.this=0x600000cfc270 id=7
    Foo::delete
    Foo::new[]
    default ctor.this=0x600003efc008 id=0
    default ctor.this=0x600003efc038 id=0
    default ctor.this=0x600003efc068 id=0
    default ctor.this=0x600003efc098 id=0
    default ctor.this=0x600003efc0c8 id=0
    dtor.this=0x600003efc0c8 id=0
    dtor.this=0x600003efc098 id=0
    dtor.this=0x600003efc068 id=0
    dtor.this=0x600003efc038 id=0
    dtor.this=0x600003efc008 id=0
    Foo::delete[]
    *///===================================
    /*virtual dtor:
    sizeof(Foo)=56// has a vptr,48+8
    Foo::new
    ctor.this=0x600001e801c0 id=7
    dtor.this=0x600001e801c0 id=7
    Foo::delete
    Foo::new[]
    default ctor.this=0x159604508 id=0
    default ctor.this=0x159604540 id=0
    default ctor.this=0x159604578 id=0
    default ctor.this=0x1596045b0 id=0
    default ctor.this=0x1596045e8 id=0
    dtor.this=0x1596045e8 id=0
    dtor.this=0x1596045b0 id=0
    dtor.this=0x159604578 id=0
    dtor.this=0x159604540 id=0
    dtor.this=0x159604508 id=0
    Foo::delete[]
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}