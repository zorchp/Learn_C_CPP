#include <iostream>
#include <complex>

#include <ext/pool_allocator.h>
using namespace std;

void t1() {
    // 1. malloc-free
    void* p1 = malloc(512);
    free(p1);
    // 2. new-delete
    complex<int>* p2 = new complex<int>;
    delete p2;
    // 3. ::operator new,(system)
    void* p3 = ::operator new(512);
    ::operator delete(p3);
}

void t2() {
#ifdef _MSC_VER
    int* p4 = allocator<int>().allocate(3, (int*)0);
    allocator<int>().deallocate(p4, 3);
#endif
#ifdef __BORLANDC__
    int* p4 = allocator<int>().allocate(5);
    allocator<int>().deallocate(p4, 5);
#endif
#ifdef __GNUC__ // gnuc2.9
    // void* p4 = alloc::allocate(512);
    // alloc::deallocate(p4, 512);

    // gnu4.9
    void* p4 = allocator<int>().allocate(7); // 7 ints
    allocator<int>().deallocate((int*)p4, 7);
    // 9 ints, need include pool_allocator
    void* p5 = __gnu_cxx::__pool_alloc<int>().allocate(9);
    __gnu_cxx::__pool_alloc<int>().deallocate((int*)p5, 9);
#endif
}

int main(int argc, char const* argv[]) {
    t1();
    // t2();
    return 0;
}
