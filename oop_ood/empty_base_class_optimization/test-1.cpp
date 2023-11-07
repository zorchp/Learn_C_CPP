#include <iostream>
using namespace std;

class Base {};

void t1() {
    cout << sizeof(Base) << endl;
    Base o1;
    Base o2;
    cout << (void *)&o1 << endl;
    cout << (void *)&o2 << endl;
    // 1
    // 0x16ba0a9a8
    // 0x16ba0a9a0
    // 存在字节对齐
}

void t2() {
    class TestC1s {
        [[maybe_unused]] Base m_obj;
        [[maybe_unused]] int m_num;
    };
    cout << sizeof(TestC1s) << endl; // 8
}

void t3() {
    class TestC2s : public Base {
        [[maybe_unused]] int m_num;
    };
    cout << sizeof(TestC2s) << endl; // 4
    // 空类作为基类, 编译器执行空基类优化
}

void t4() {
    class TestC3s : public Base {};
    cout << sizeof(TestC3s) << endl; // 1
}

void t5() {
    // 特例:
    class TestC4s : public Base {
    public:
        [[maybe_unused]] Base m_obj;
        [[maybe_unused]] int m_num;
    };
    cout << sizeof(TestC4s) << endl; // 8, 说明未执行 ebo
    // cout << static_cast<void *>(&TestC4s::m_obj) << endl;
    printf("%p\n", &TestC4s::m_obj); // 0x1
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    // t4();
    t5();
    return 0;
}
