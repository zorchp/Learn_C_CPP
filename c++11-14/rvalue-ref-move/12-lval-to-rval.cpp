#include <iostream>

using namespace std;


void t1() {
    int a = 10;
    // int&& k = a; // error,左值不能绑定到右值
}


void t2() {
    int b = 10;
    //它的最大作用是让左值使用移动语义
    int&& k = static_cast<int&&>(b); //类型强制转换可以
    int&& l = std::move(b);          // move函数可以
}


int main(int argc, char const* argv[]) {
    t1();
    t2();
    return 0;
}