#include <iostream>
using namespace std;
class HasPtrMem {
public:
    HasPtrMem() : d(new int(3)) { cout << "Construct: " << ++n_cstr << endl; }
    HasPtrMem& operator=(HasPtrMem&& h) noexcept { // 移动赋值函数
        // 检测自赋值
        if (this != &h) {
            delete d;      // 释放已有对象
            d = h.d;       // 完成赋值
            h.d = nullptr; // 将h置于可析构状态
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
    static int n_mvas;
};
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_mvas = 0;
int main() {
    HasPtrMem a, b;
    b = std::move(a);
    cout << "Resource from " << __func__ << ": " << hex << a.d << endl;
    cout << "Resource from " << __func__ << ": " << hex << b.d << endl;
}

/* :!clang++
 * c++11-14/Depth_understanding_of_C++11/chap3/move-semantic-perfect-forward/3-19-1-move-assignment.cpp
 * -fno-elide-constructors -std=c++ */
/* 11 && ./a.out */
/* Construct: 1 */
/* Construct: 2 */
/* Move assignment: 1 */
/* Resource from main: 0x0 */
/* Resource from main: 0x600001c4c040 */
/* Destruct: 1 */
/* Destruct: 2 */
