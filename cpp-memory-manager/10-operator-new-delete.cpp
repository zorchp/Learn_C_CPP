#include <iostream>
using namespace std;

namespace jj12 {

class Foo {
public:
    long _x;

public:
    Foo(long x = 0) : _x(x) {}

    //! static void* operator new(size_t size) = default; //[Error] cannot be
    //! defaulted static void  operator delete(void* pdead, size_t size) =
    //! default;   //[Error] cannot be defaulted
    static void* operator new[](size_t size)                = delete;
    static void operator delete[](void* pdead, size_t size) = delete;
};

class Goo {
public:
    long _x;

public:
    Goo(long x = 0) : _x(x) {}

    static void* operator new(size_t size)                = delete;
    static void operator delete(void* pdead, size_t size) = delete;
};

void test_delete_and_default_for_new() {
    cout << "\n\n\ntest_delete_and_default_for_new().......... \n";

    Foo* p1 = new Foo(5);
    delete p1;
    //! Foo* pF = new Foo[10];  //[Error] use of deleted function 'static void*
    //! jj12::Foo::operator new [](size_t)' delete [] pF;           //[Error]
    //! use of deleted function 'static void jj12::Foo::operator delete
    //! [](void*, size_t)'

    //! Goo* p2 = new Goo(7);   //[Error] use of deleted function 'static void*
    //! jj12::Goo::operator new(size_t)' delete p2;              //[Error] use
    //! of deleted function 'static void jj12::Goo::operator delete(void*,
    //! size_t)'
    Goo* pG = new Goo[10];
    delete[] pG;
}
} // namespace jj12

int main(int argc, char const* argv[]) {
    jj12::test_delete_and_default_for_new();
    return 0;
}