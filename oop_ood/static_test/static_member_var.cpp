#include <iostream>

using namespace std;

/*
    类内声明, 类外初始化
    存在访问权限
    可以采用类名直接调用
*/
class P {
public:
    static int ma;

    P();
    ~P();

private:
    static int mb;
};

int P::ma = 10;
int P::mb = 20;

void t1() {
    cout << P::ma << endl; // 10
    P::ma = 100;
    cout << P::ma << endl; // 100
}


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}