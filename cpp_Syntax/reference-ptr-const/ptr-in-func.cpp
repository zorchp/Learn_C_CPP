#include <iostream>

using namespace std;
int x = 10;
void t1(int*& p) {
    // 直接通过指针修改, 看不出指针变量被传值(复制)
    //  *p = 89;
    cout << "t1 1: " << hex << p << endl;
    p = &x; // 仅仅改变了指向
    cout << "t1 2: " << hex << p << endl;
}

int main(int argc, char const* argv[]) {
    int a = 9, *pa = &a;
    cout << "main: " << hex << pa << endl;

    t1(pa);
    cout << dec << a << endl;
    cout << hex << &a << endl;
    cout << dec << *pa << endl;
    return 0;
}