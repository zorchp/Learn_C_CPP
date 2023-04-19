#include <iostream>
using namespace std;
class HasPtrMem {
public:
    HasPtrMem() : d(new int(3)) { cout << "Construct: " << ++n_cstr << endl; }
    HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {
        cout << "Copy construct: " << ++n_cptr << endl;
    }
    HasPtrMem(HasPtrMem&& h) : d(h.d) { // 移动构造函数
        h.d = nullptr;                  // 将临时值的指针成员置空
        cout << "Move construct: " << ++n_mvtr << endl;
    }
    HasPtrMem& operator=(HasPtrMem&& h) noexcept { // 移动赋值函数
        // 检测自赋值
        if (this != &h) {
            delete d;
            d = h.d;
            h.d = nullptr;
            cout << "Move assignment: " << ++n_mvas << endl;
        }
        return *this;
    }
    ~HasPtrMem() {
        delete d;
        cout << "Destruct: " << ++n_dstr << endl;
    }
    int* d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
    static int n_mvas;
};
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;
int HasPtrMem::n_mvas = 0;
HasPtrMem GetTemp() {
    HasPtrMem h;
    cout << "Resource from " << __func__ << ": " << hex << h.d << endl;
    return h;
}
int main() {
    HasPtrMem a, b;
    b = std::move(b);
    cout << "Resource from " << __func__ << ": " << hex << b.d << endl;
}
// 编译选项:g++ -std=c++11 3-3-4.cpp -fno-elide-constructors
/* :!g++ 3-19-move-ctor.cpp -fno-elide-constructors -std=c++11 &&./a.out */
/* Construct: 1 */
/* Resource from GetTemp: 0x600000018040 */
/* Move construct: 1 */
/* Destruct: 1 */
/* Move construct: 2 */
/* Destruct: 2 */
/* Resource from main: 0x600000018040 */
/* Destruct: 3 */
