#include <cstdio>
#include <iostream>
using namespace std;

class P {
public:
    int x;
    int array_[1]; // Must be declared at the end of the class
};

void t1() {
    cout << "sizeof(P)=" << sizeof(P) << endl; // 8
    // 24=4+5*4, array_.size=5
    // auto p = (P*)malloc(24); // definition
    P* p = new P; // can not alloc with size

    new (p + sizeof(P)) int[4]; // ASan may check error


    p->array_[0] = 1;
    p->array_[1] = 2;
    p->array_[2] = 3;
    p->array_[4] = 3;
    for (int i{}; i < 5; ++i)
        cout << p->array_[i] << endl;
    // 1
    // 2
    // 3
    // -1094795586
    // 3
}

void t2() {
    char a[0];
    printf("%p\n", a);
    char b[0];
    printf("%p\n", b);
}

int main(int argc, char* argv[]) {
    t1();
    // t2();
    return 0;
}
