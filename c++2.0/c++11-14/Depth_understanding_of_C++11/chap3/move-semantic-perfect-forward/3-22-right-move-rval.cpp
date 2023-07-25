#include <iostream>
using namespace std;
class HugeMem {
public:
    HugeMem(int size) : sz(size > 0 ? size : 1) { c = new int[sz]; }
    ~HugeMem() { delete[] c; }
    HugeMem(HugeMem&& hm) : sz(hm.sz), c(hm.c) { hm.c = nullptr; }
    HugeMem(const HugeMem& hm) : c(new int[hm.sz]) {
        cout << "call copy ctor\n";
    }
    int sz;
    int* c;
};
class Moveable {
public:
    Moveable() : i(new int(3)), h(1024) {}
    ~Moveable() { delete i; }
    Moveable(Moveable&& m) : i(m.i), h(m.h) {
        // 强制转为右值，以调用移动构造函数
        /* : i(m.i), h(std::move(m.h)) { */
        m.i = nullptr;
    }
    int* i;
    HugeMem h;
};
Moveable GetTemp() {
    Moveable tmp = Moveable();
    cout << hex << "Huge Mem from " << __func__ << " @" << tmp.h.c
         << endl; // Huge Mem from GetTemp @0x603030
    return tmp;
}
int main() {
    Moveable a(GetTemp());
    cout << hex << "Huge Mem from " << __func__ << " @" << a.h.c
         << endl; // Huge Mem from main @0x603030
}
// 编译选项:g++ -std=c++11 3-3-7.cpp -fno-elide-constructors
// 若不使用move, 那么必然调用copy ctor, 情况如下(编译需要加上参数):
/* call copy ctor */
/* Huge Mem from GetTemp @0x150009800 */
/* call copy ctor */
/* call copy ctor */
/* Huge Mem from main @0x12fe00000 */
