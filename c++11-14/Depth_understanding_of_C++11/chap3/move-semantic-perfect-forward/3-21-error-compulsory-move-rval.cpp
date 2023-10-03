#include <iostream>
using namespace std;
class Moveable {
public:
    Moveable() : i(new int(3)) {}
    ~Moveable() { delete i; }
    Moveable(const Moveable& m) : i(new int(*m.i)) {}
    Moveable(Moveable&& m) : i(m.i) {
        m.i = nullptr; // 临时变量置空
    }
    int* i;
};
class Moveable_String {
public:
    Moveable_String() : i(new string("hello")) {}
    ~Moveable_String() { delete i; }

    Moveable_String(const Moveable_String& m) : i(new string(*m.i)) {}
    Moveable_String(Moveable_String&& m) : i(m.i) {
        m.i = nullptr; // 临时变量置空
    }
    string* i;
};
void t1() {
    Moveable a;
    Moveable c(std::move(a)); // 会调用移动构造函数
    /* Moveable c((Moveable())); // 会调用移动构造函数 */
    cout << a.i << endl; // 运行时错误
}
void t2() {
    Moveable_String a;
    Moveable_String c(std::move(a));
    cout << *a.i << endl;
}
int main() {
    t1();
    /* t2(); */
}
// 编译选项:g++ -std=c++11 3-3-6.cpp -fno-elide-constructors
