// C++ Program demonstrate if the cast
// fails and new_type is a pointer type
// it returns a null pointer of that type
#include <iostream>
using namespace std;

// Base class declaration
class Base {
    virtual void print() { cout << "Base" << endl; }
};

// Derived1 class declaration
class Derived1 : public Base {
    void print() { cout << "Derived1" << endl; }
};

// Derived2 class declaration
class Derived2 : public Base {
    void print() { cout << "Derived2" << endl; }
};

// Driver Code
int main() {
    Derived1 d1;
    Base* bp = dynamic_cast<Base*>(&d1);

    // Dynamic Casting
    Derived2* dp2 = dynamic_cast<Derived2*>(bp); //类型转换失败,返回空指针
    if (dp2 == nullptr) cout << "null" << endl;

    return 0;
}
