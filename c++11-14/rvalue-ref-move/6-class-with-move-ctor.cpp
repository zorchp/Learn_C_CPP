#include <iostream>
#include <vector>
using namespace std;
/*移动语义在线程库中大量使用，既可以取代不合理的复制语义，又可以实现资源转移。另外，按代码逻辑流程，某些对象注定要销毁，但我们却想延展其所含的数据。若复制操作的开销大，就可以改用转移来进行优化。*/

class X {
private:
    int* data;

public:
    X() : data(new int[1000000]) {}
    ~X() { delete[] data; }
    // 传统的拷贝构造函数
    X(const X& other) : data(new int[1000000]) {
        std::copy(other.data, other.data + 1000000, data);
    }
    // 移动构造函数
    X(X&& other) : data(other.data) { other.data = nullptr; }
};

void t1() {
    X x1;
    X x2 = std::move(x1);
    X x3 = static_cast<X&&>(x2);
    cout << &x1 << endl;
    cout << &x2 << endl;
    cout << &x3 << endl;
    /*0x16f597088
0x16f597080
0x16f597078*/
}
void do_stuff(X&& x_) {
    X a(x_);
    //复制构造
    X b(std::move(x_));
    //移动构造
}
void t2() {
    do_stuff(X());
    //正确，X() 生成一个匿名临时对象，作为右值与右值引用绑定
    X x;
    // do_stuff(x);
    //错误，具名对象x是左值，不能与右值引用绑定
}
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}