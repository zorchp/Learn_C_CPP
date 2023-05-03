#include <iostream>
using namespace std;


void t1() {
    auto p = new int(1);
    delete p;
    cout << typeid(p).name() << endl; // Pi
    cout << (p == nullptr) << endl;   // 0
    // C++ Primer 5ed P411
    p = nullptr; // 删除指针所指向的内存之后, 将指针置为空是有必要的
    cout << (p == nullptr) << endl; // 1
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}