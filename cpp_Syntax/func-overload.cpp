#include <iostream>
using namespace std;

// 返回值不能重载, 所以返回值不属于函数签名
// error: functions that differ only in their return type cannot be overloaded
int func() { return 1; }
// void func() {}

void t1() {
    int a = func();
    cout << a << endl;
}


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}