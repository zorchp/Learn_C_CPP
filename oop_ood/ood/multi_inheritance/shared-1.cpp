// 下列程序的运行结果是（）
#include <iostream>
using namespace std;

class B {
public:
    int b;
    B() { b = 0; }
};
class B1 : virtual public B {
private:
    int b1;
};
class B2 : virtual public B {
private:
    int b2;
};
class C : public B1, public B2 {
private:
    float d;
};
int main() {
    C c1;
    cout << c1.b << endl; // 0
    return 0;
}