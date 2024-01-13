#include <iostream>

template <typename Derived>
class Base {
public:
    void foo() {
        std::cout << "this is Base::foo()\n";
        // this->fooimpl();
        static_cast<Derived *>(this)->fooimpl();
    }
};

class Derived : public Base<Derived> {
public:
    void fooimpl() {
        //
        std::cout << "this is Derived::fooimpl()\n";
    }
};

int main(int argc, char *argv[]) {
    Derived d;
    d.foo(); // call derived method

    // this is Base::foo()
    // this is Derived::fooimpl()

    d.fooimpl();
    // this is Derived::fooimpl()
    return 0;
}
