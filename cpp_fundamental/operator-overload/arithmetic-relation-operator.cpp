#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class P {
    friend ostream& operator<<(ostream&, const P&);
    friend P operator+(const P& lhs, const P& rhs);

public:
    P() {}
    P(int a1_, int a2_) : a1(a1_), a2(a2_) {}
    P operator+(const P&); //成员函数版, 有就先用

private:
    int a1;
    int a2;
};

ostream& operator<<(ostream& os, const P& p) {
    os << "(a1=" << p.a1 << " a2=" << p.a2 << ")";
    return os;
}

P P::operator+(const P& p) {
    cout << "member-function" << endl;
    return P(this->a1 + p.a1, this->a2 + p.a2);
}

P operator+(const P& lhs, const P& rhs) { //非成员函数版本
    // ===========返回引用:=====================
    // P p(lhs.a1 + rhs.a1, lhs.a2 + rhs.a2);
    // P& rp = p;
    // return rp;//此时用ref得到的是被销毁的值:undefined
    // =============================================
    // P* pp = new P(lhs.a1 + rhs.a1, lhs.a2 + rhs.a2);
    // P& rp = *pp;//但是这块内存不会被销毁, 所以使用智能指针
    // return rp;
    // ===========================================================
    // auto pp = make_shared<P>(P(lhs.a1 + rhs.a1, lhs.a2 + rhs.a2));
    // P& rp = *pp;
    // return rp;
    // ====非引用:=========================
    cout << "non-member-function" << endl;
    // P p(lhs.a1 + rhs.a1, lhs.a2 + rhs.a2);
    // return p;
    return P(lhs.a1 + rhs.a1, lhs.a2 + rhs.a2);
}

void t1() {
    P p1(1, 2), p2(3, 4);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << "p1+p2=" << p1 + p2 << endl;
    cout << "p1+p2=" << p1.operator+(p2) << endl;
    cout << "p1+p2=" << operator+(p1, p2) << endl;
    /*
    (a1=1 a2=2)
    (a1=3 a2=4)
    p1+p2=member-function
    (a1=4 a2=6)
    p1+p2=member-function
    (a1=4 a2=6)
    p1+p2=non-member-function
    (a1=4 a2=6)
    */
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}
