#include <iostream>
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
    // ~Foo() { cout << "dtor.this=" << this << " id=" << _id << endl; }
    // virtual ~Foo() { cout << "dtor.this=" << this << " id=" << _id << endl; }

    static void* operator new(size_t size);
    static void operator delete(void* pdead, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead, size_t size);
};

void* Foo::operator new(size_t size) {
    Foo* p = (Foo*)malloc(size);
    cout << "Foo::new, size=" << size << endl;
    return p;
}

void Foo::operator delete(void* pdead, size_t size) {
    cout << "Foo::delete, size=" << size << endl;
    free(pdead);
}

void* Foo::operator new[](size_t size) {
    Foo* p = (Foo*)malloc(size);
    cout << "Foo::new[], size=" << size << endl;
    return p;
}

void Foo::operator delete[](void* pdead, size_t size) {
    cout << "Foo::delete[], size=" << size << endl;
    free(pdead);
}


void t1() {
    Foo* pf = new Foo;
    delete pf;

    Foo* pf1 = ::new Foo;
    ::delete pf1;
    /*
    Foo::new, size=56
    default ctor.this=0x600001ccc1c0 id=0
    dtor.this=0x600001ccc1c0 id=0
    Foo::delete
    */

    // if not overload new and delete: call system new and delete
    /*
    default ctor.this=0x600001cc8000 id=0
    dtor.this=0x600001cc8000 id=0
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
    Foo::new, size=48
    ctor.this=0x600000f18000 id=7
    sizeof(new Foo)=48
    dtor.this=0x600000f18000 id=7
    Foo::delete
    Foo::new[], size=248
    default ctor.this=0x600003d1c008 id=0
    default ctor.this=0x600003d1c038 id=0
    default ctor.this=0x600003d1c068 id=0
    default ctor.this=0x600003d1c098 id=0
    default ctor.this=0x600003d1c0c8 id=0
    sizeof(new Foo[5])=48
    dtor.this=0x600003d1c0c8 id=0
    dtor.this=0x600003d1c098 id=0
    dtor.this=0x600003d1c068 id=0
    dtor.this=0x600003d1c038 id=0
    dtor.this=0x600003d1c008 id=0
    Foo::delete[]
    */
    //===================================
    /*
    sizeof(Foo)=56
    Foo::new, size=56
    ctor.this=0x6000039701c0 id=7
    sizeof(new Foo)=56
    dtor.this=0x6000039701c0 id=7
    Foo::delete
    Foo::new[], size=288
    default ctor.this=0x139e04588 id=0
    default ctor.this=0x139e045c0 id=0
    default ctor.this=0x139e045f8 id=0
    default ctor.this=0x139e04630 id=0
    default ctor.this=0x139e04668 id=0
    sizeof(new Foo[5])=56
    dtor.this=0x139e04668 id=0
    dtor.this=0x139e04630 id=0
    dtor.this=0x139e045f8 id=0
    dtor.this=0x139e045c0 id=0
    dtor.this=0x139e04588 id=0
    Foo::delete[]
    */
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}