#include <iostream>
// #include <new>
using namespace std;
/*placement-new*/

class Bad {};
class Foo {
public:
    Foo() { cout << "Foo::Foo()" << endl; }
    Foo(int) {
        cout << "Foo::Foo(int)" << endl;
        throw Bad(); // 这里给出一个异常的例子
    }
    // new
    static void* operator new(size_t size); // 一般的重载
    static void* operator new(size_t size,
                              void* start); // 标准库提供的placement new()重载
    static void* operator new(size_t size, long extra); // 新的placement new()
    static void* operator new(size_t size, long extra,
                              char init); // 另一个新的placement new()
    // static void* operator new(long extra, char init);
    // error, **第一参数必须是size_t类型**

    /*可以重载对应版本的operator delete(), 但是不会被调用,
    只有当operator new()调用的ctor抛出异常时候, 才会调用这些重载版本的delete(),
    也只可能被这样调用, 用途是归还未能完全创建成功的object占用的内存memory
    */

    static void operator delete(void*, size_t);
    static void operator delete(void*, void*);
    static void operator delete(void*, long);
    static void operator delete(void*, long, char);

private:
    int m_i;
};


void* Foo::operator new(size_t size) {
    cout << "operator new(size_t size), size=" << size << endl;
    return malloc(size);
}

void* Foo::operator new(size_t size, void* start) {
    cout << "operator new(size_t size, void* start), size=" << size
         << ", start=" << start << endl;
    return start;
}

void* Foo::operator new(size_t size, long extra) {
    cout << "operator new(size_t size, long extra), size=" << size
         << ", extra=" << extra << endl;
    return malloc(size + extra);
}

void* Foo::operator new(size_t size, long extra, char init) {
    cout << "operator new(size_t size, long extra, char init), size=" << size
         << ", extra=" << extra << ", init=" << init << endl;
    return malloc(size + extra);
}

// void* Foo::operator new(long extra, char init) {
//     //error: 'operator new' takes type size_t ('unsigned long') as first
//     parameter return malloc(extra);
// }

void Foo::operator delete(void*, size_t) {
    cout << "operator delete(void*, size_t)" << endl;
}

void Foo::operator delete(void*, void*) {
    cout << "operator delete(void*, size_t)" << endl;
}

void Foo::operator delete(void*, long) {
    cout << "operator delete(void*, long)" << endl;
}

void Foo::operator delete(void*, long, char) {
    cout << "operator delete(void*, long, char)" << endl;
}


void t1() {
    Foo* pf = new (300, 'c') Foo;
    delete pf;
    /*
    Foo::Foo()
    operator delete(void*, size_t)
    */
}

void t2() {
    Foo start;
    Foo* p1 = new Foo;
    Foo* p2 = new (&start) Foo;
    Foo* p3 = new (100) Foo;
    Foo* p4 = new (100, 'a') Foo;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    /*
    Foo::Foo()
    operator new(size_t size), size=4
    Foo::Foo()
    operator new(size_t size, void* start), size=4, start=0x16f35b04c
    Foo::Foo()
    operator new(size_t size, long extra), size=4, extra=100
    Foo::Foo()
    operator new(size_t size, long extra, char init), size=4, extra=100, init=a
    Foo::Foo()
    operator delete(void*, size_t)
    operator delete(void*, size_t)
    operator delete(void*, size_t)
    operator delete(void*, size_t)
    */
}

void t3() {
    Foo start;
    Foo* p5 = new (100) Foo(1);
    // delete p5;
    /*
    Foo::Foo()
    operator new(size_t size, long extra), size=4, extra=100
    Foo::Foo(int)
    libc++abi: terminating with uncaught exception of type Bad
    [1]    10066 abort
    */
    // Foo* p6 = new(100, 'a') Foo(1);
    // Foo* p7 = new(&start) Foo(1);
    // Foo* p8 = new Foo(1);
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
