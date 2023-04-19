#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {}
    ~Shape() {}
    virtual double Area() = 0;
};
class C : public Shape {
public:
    C(double r) : i(r) {}
    double Area() { return 3.14 * i * i; }

private:
    double i;
};
int main() {
    Shape* sp;
    sp = new C(5);
    cout << sp->Area() << endl;
    delete sp; // 声明非虚析构函数, 仅warning
    return 0;
}