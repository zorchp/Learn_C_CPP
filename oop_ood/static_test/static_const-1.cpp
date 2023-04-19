#include <iostream>
#include <vector>
using namespace std;

class P {
public:
    static const int cma;
    // 如果只在类内声明并初始化, 就不能取地址, 不能引用
};
void t0() {
    cout << P::cma << endl; //
}

const int P::cma{10};
void t1() {
    P p;
    cout << P::cma << endl; // 0
    cout << p.cma << endl;  // 0
    // 如果没有类外定义, 取地址, 引用会发生链接期错误
    // auto p1 = &p.cma;       // error
    // const int &p2 = p.cma;  // error
    // auto q1 = &P::cma;      // error
    // const int &q2 = P::cma; // error
    // cout << p1 << endl;     // 0x1046e3be0
    // cout << q1 << endl;     // 0x1046e3be0
    // cout << p2 << endl;     // 0
    // cout << q2 << endl;     // 0
}
void f(int t) {}
void t11() {
    vector<int> v(P::cma); // 数组长度
    f(P::cma);             // 作为实参
}

template <typename T>
class Q {
public:
    static const T cma;
    // 如果只在类内声明并初始化, 就不能取地址, 不能引用
};

// 类外义务性定义, 不能少
template <typename T>
const T Q<T>::cma{10};

template <>
const long Q<long>::cma{20};


void t2() {
    Q<int> q;
    cout << Q<int>::cma << endl; // 0
    cout << q.cma << endl;       // 0
    // 如果没有类外定义, 取地址, 引用会发生链接期错误
    // auto p1 = &q.cma;            // error
    // const int &p2 = q.cma;       // error
    // auto q1 = &Q<int>::cma;      // error
    // const int &q2 = Q<int>::cma; // error
    // cout << p1 << endl;          // 0x104167e54
    // cout << q1 << endl;          // 0x104167e54
    // cout << p2 << endl;          // 0
    // cout << q2 << endl;          // 0
}

struct MyInt {
    int i;
    MyInt(int _i) : i(_i) {}
};

void t3() {
    cout << Q<int>::cma << endl;
    cout << Q<long>::cma << endl;
    // Q<MyInt> qmi; // error, 必须类外初始化
}

int main(int argc, char const *argv[]) {
    t0();
    // t1();
    // t11();
    // t2();
    // t3();
    return 0;
}