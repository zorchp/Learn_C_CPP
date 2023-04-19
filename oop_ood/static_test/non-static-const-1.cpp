#include <iostream>

using namespace std;

class P {
public:
    const int cma{}; // 如果只在类内声明并初始化, 就不能取地址, 不能引用
};

void t1() {
    P p;
    cout << p.cma << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}