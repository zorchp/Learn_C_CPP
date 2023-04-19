#include <iostream>
using namespace std;
class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {}
    // 拷贝构造函数，从堆中分配内存，并用*h.d初始化
    HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {}
    ~HasPtrMem() { delete d; }
    int* d;
};
int main() {
    HasPtrMem a;
    HasPtrMem b(a);
    cout << *a.d << endl; // 0
    cout << *b.d << endl; // 0
} // 正常析构
