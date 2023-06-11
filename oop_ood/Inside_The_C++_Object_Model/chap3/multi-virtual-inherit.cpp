#include <iostream>

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

int main(int argc, char* argv[]) {
    std::cout << sizeof(X) << '\n'; // 1
    std::cout << sizeof(Y) << '\n'; // 8
    std::cout << sizeof(Z) << '\n'; // 8
    std::cout << sizeof(A) << '\n'; // 16
    // 如果没有 virtual(虚继承), 则基类不是虚基类, 结果为 1,1,1,2
    return 0;
}
