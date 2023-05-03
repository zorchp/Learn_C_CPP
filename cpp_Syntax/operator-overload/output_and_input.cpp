#include <iostream>
#include <string>
#include <vector>
using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it == v.end() - 1 ? "}" : ", ");
    return os;
}

void t1() {
    // overload <<
    vector<int> v{1, 2, 3};
    cout << "v=" << v << endl; // v={1, 2, 3}
}

struct P {
    int age{};
    string name{};
    //假如将输出运算符重载为类的成员函数:
    ostream& operator<<(ostream&);
};

ostream& P::operator<<(ostream& os) {
    os << "name:" << name << " age: " << age;
    return os;
}

void t2() {
    P p1;
    p1.age = 10;
    p1.name = "tom";
    // cout << p1 << endl;//error
    // 这里就必须颠倒过来
    p1 << cout << endl;
    cout << p1.age << endl;
    cout << p1.name << endl;
    /*
name:tom age: 10
10
tom
    */
}

struct Q {
    int age{};
};

istream& operator>>(istream& is, Q& q) { //第二参数为非常量
    int age;
    is >> age;
    if (is)
        q.age = age;
    else
        q = Q();
    return is;
}

void t3() {
    Q q;
    cin >> q;
    cout << q.age << endl;
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}