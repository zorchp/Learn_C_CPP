#include <iostream>
using namespace std;

class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {}
    // 拷贝构造函数，从堆中分配内存，并用*h.d初始化
    /* HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {} */
    ~HasPtrMem() { delete d; }
    int* d;
};
int main() {
    HasPtrMem a;
    HasPtrMem b(a);
    cout << *a.d << endl; // 0
    cout << *b.d << endl; // 0
}
/* 0 */
/* 0 */
/* 3-16-shallow-copy-with-mem-leak.out(63434,0x103138580) malloc: *** error for
 * object 0x60000366c040: pointer being freed was not allocate */
/* d */
/* 3-16-shallow-copy-with-mem-leak.out(63434,0x103138580) malloc: *** set a
 * breakpoint in malloc_error_break to debug */

/* a.d和b.d都指向了同一块堆内存。因此在main作用域结束的时候，a和b的析构函数纷纷被调用
 * 当其中之一完成析构之后（比如b），那么a.d就成了一个“悬挂指针”（dangling
 * pointer），因为其不再指向有效的内存了。那么在该悬挂指针上释放内存就会造成严重的错误。
 */
