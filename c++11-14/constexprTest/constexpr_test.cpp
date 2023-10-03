#include <iostream>
using namespace std;

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

const int *p = nullptr;     // p是一个指向整型常量的指针
constexpr int *q = nullptr; // q是一个指向整数的指针常量,top-const

void test1() {
    cout << new_sz() << endl;
    cout << foo << endl;
}

void test2() {
    int i = 10;
    p = &i;
    // p=10;
    // q=&i;
}

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }

void test3() {
    int arr[scale(2)];
    int i = 2;
    int a2[scale(i)]; // 未出现错误, 想想为什么
    cout << scale(i) << endl;
}


int main(int argc, char const *argv[]) {
    // test1();
    // test2();
    test3();

    return 0;
}