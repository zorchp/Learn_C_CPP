#include <bits/stdc++.h>
using namespace std;

void t1() {
    // new 在栈上
    int a = 10, *pa = &a;
    new (pa) int(12);
    cout << a; // 12
}

void t2() {
    // 自定义类型, 通过 new on stack 使其不调用析构函数
}

int main(int argc, char const *argv[]) {
    //
    t1();
    return 0;
}
