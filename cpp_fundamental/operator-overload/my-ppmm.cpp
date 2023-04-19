#include <iostream>
#include <vector>

using namespace std;

class MyInt {
public:
    MyInt() : m_i(0) {}
    MyInt(int i) : m_i(i) {}
    ~MyInt() {}
    // prefix ++
    MyInt& operator++() { // 加上&引用使得++可以重复调用
        ++(this->m_i);
        return *this;
    }

    // postfix ++, const 防止重复调用
    const MyInt operator++(int) {
        MyInt tmp = *this;
        ++*this; // 这里用到了重载的prefix++, 保证接口只需修改前置++
        return tmp; // 返回原对象, 局部变量不能返回引用, 否则会销毁
    }
    int m_i;
};

void t1() {
    vector<int> v{0, 1, 2, 3, 4, 5};
    MyInt myint(1);
    cout << myint.m_i << endl;      // 1
    cout << v[myint.m_i++] << endl; // 1
    cout << myint.m_i << endl;      // 2
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}