#include <iostream>
using namespace std;

void print(int *arr) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

class A {
public:
    A() : m_i(0) {}
    A(int i) : m_i(i) {}
    ~A() {}
    // prefix ++
    A &operator++() { // 加上&引用使得++可以重复调用
        ++(this->m_i);
        return *this;
    }

    // postfix ++
    A operator++(int) {
        A tmp = *this;
        ++*this;    // 这里用到了重载的prefix ++
        return tmp; // 局部变量不能返回引用, 否则会销毁
    }
    int m_i;
};

void t1() {
    A a1, a2, a3, a4;
    std::cout << "a1=" << a1.m_i << endl;
    a1 = a1++;
    std::cout << "a1=" << a1.m_i << endl;
    std::cout << "a2=" << a2.m_i << endl;
    a2 = ++a2;
    std::cout << "a2=" << a2.m_i << endl;
    /*
    a1=0
    a1=0
    a2=0
    a2=1
    */
}
void t2() {
    A a1, a2;
    std::cout << "a1=" << (a1++).m_i << endl;
    std::cout << "a2=" << (++a2).m_i << endl;
    std::cout << "a1=" << a1.m_i << endl;
    std::cout << "a2=" << a2.m_i << endl;
    /*
    a1=0
    a2=1
    a1=1
    a2=1
    */
}
void t3() {
    A a1, a2;
    // std::cout << "a1=" << ((a1++).m_i++).m_i << endl;//error: using rvalue as
    // lvalue [-fpermissive]
    std::cout << "a2=" << (++ ++a2).m_i << endl;
    std::cout << "a1=" << a1.m_i << endl;
    std::cout << "a2=" << a2.m_i << endl;
    /*
    a2=2
    a1=0
    a2=2
    */
}
int main(int argc, char *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
