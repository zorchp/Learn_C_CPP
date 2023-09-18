#include <iostream>
using namespace std;

class B1 {
public:
    virtual void f1() {}
};
class B2 {
public:
    virtual void f1() {}
};

class D : public virtual B1, public virtual B2 {
public:
    ~D() {}
    void f1() {}
};

void t1() {
    cout << sizeof(B1) << endl; // 8
    cout << sizeof(B2) << endl; // 8
    cout << sizeof(D) << endl;  // 16
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
