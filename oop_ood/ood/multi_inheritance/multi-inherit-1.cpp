#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct Base1 {
    Base1() { cout << "Base1()\n"; }
    Base1(const string &) { cout << "Base1(const string&) \n"; }
    Base1(std::shared_ptr<int>);
};

struct Base2 {
    Base2() { cout << "Base2()\n"; }
    Base2(const string &) { cout << "Base2(const string&) \n"; }
    Base2(int a) { cout << "Base2(int)\n"; }
};

struct D1 : public Base1, public Base2 {
    using Base1::Base1;
    using Base2::Base2;
    // 定义自己版本的构造函数
    D1(const string &) { cout << "D1(const string &)\n"; }
};

void t1() {
    D1 d1(1);
    /* Base1() */
    /* Base2(int) */
}
void t2() {
    D1 d2("abc");
    /* error: call of overloaded 'D1(const char [4])' is ambiguous */
    /* Base1() */
    /* Base2() */
    /* D1(const string &) */
}

int main(int argc, char *argv[]) {
    // test
    /* t1(); */
    t2();

    return 0;
}
