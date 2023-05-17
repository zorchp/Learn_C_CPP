#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <new>
using namespace std;

/*placement-new 允许我们将对象 建构在allocated memory(已分配好的内存)中,
但是没有placement-delete, 因为并没有额外分配内存,
或者可以称呼与placement-new对应的是placement-delete.
placement-new:等同于调用构造函数.
*/

void t1() {
    void* buf = new char[sizeof(complex<int>) * 3];
    complex<int>* pc = static_cast<complex<int>*>(buf);
    new (&pc[0]) complex<int>(1, 2);
    new (&pc[1]) complex<int>(2, 3);
    // 这里其实调用了下面的:
    // static void* operator new(size_t size, void* start);
    printf("buf=%p\n", buf);
    printf("pc=%p\n", pc);
    /* buf=0x600001bc1100 */
    /* pc=0x600001bc1100 */

    cout << pc->real() << " " << pc->imag() << endl;     // 1,2
    cout << pc[1].real() << " " << pc[1].imag() << endl; // 2,3
    // 标准库提供的placement new()重载

    // delete[] pc;  // ok
    // delete[] buf; //ok
    // operator delete[](buf); // ok
    delete pc; // ok
}
int main(int argc, char const* argv[]) {
    t1();
    return 0;
}
