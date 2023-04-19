#include <iostream>
using namespace std;
class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) { cout << "Construct: " << ++n_cstr << endl; }
    HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {
        cout << "Copy construct: " << ++n_cptr << " " << hex << h.d << endl;
    }
    ~HasPtrMem() { cout << "Destruct: " << ++n_dstr << endl; }
    int* d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
};
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
HasPtrMem GetTemp() { return HasPtrMem(); }
int main() { HasPtrMem a = GetTemp(); }

// 两次拷贝构造, 两份不同的堆内存(但是相同的数据). 开销很大
/* :!clang++ 3-18-record-call-ctor-count.cpp -fno-elide-constructors -std=c++11
 * &&./a.out */
/* Construct: 1 */
/* Copy construct: 1 0x6000003ac040 */
/* Destruct: 1 */
/* Copy construct: 2 0x6000003ac050 */
/* Destruct: 2 */
/* Destruct: 3 */
