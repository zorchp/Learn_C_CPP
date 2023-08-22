#include <iostream>
class P {
public:
    void f() { static int x = 10; }
    void g() {
        //
    }
};

void t1() {
    P p;
    p.f();
    std::cout << sizeof(P) << std::endl; // 1
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
