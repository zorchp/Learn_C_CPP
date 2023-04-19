#include <iostream>
using namespace std;

class P {
public:
    static int cma; // 如果只在类内声明并初始化, 就不能取地址, 不能引用
};
int P::cma{};
void t1() {
    P p;
    cout << P::cma << endl; // 0
    cout << p.cma << endl;  // 0
}

int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}