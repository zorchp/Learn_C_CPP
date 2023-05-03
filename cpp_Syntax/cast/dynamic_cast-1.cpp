#include <iostream>

struct P {
    int a;
};

struct PP : P {
    int b;
};


void t1() {
    PP pp1;
    // 派生类转化为相应的基类
    P p = dynamic_cast<P &>(pp1);
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}