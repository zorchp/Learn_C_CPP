#include <iostream>
using namespace std;

void f(int);
void f(void *);
// void f(nullptr);

void f(int a) { cout << a << endl; }

void f(void *) { //任意类型的指针
    cout << "void*" << endl;
}

void t1() {
    f(11);
    int a = 1, *p = &a;
    f(p);
    f(NULL); // NULL 可以被隐式类型转换为0, 此时会出现ambiguous,
             // 所以C++11采用新的关键字(对象)nullptr
}

int main(int argc, char const *argv[]) {
    t1();

    return 0;
}
