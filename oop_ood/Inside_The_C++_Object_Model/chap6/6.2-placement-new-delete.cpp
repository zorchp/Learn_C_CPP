#include <iostream>

class X {
public:
    X() {
        std::cout << "X()\n";
    }
    ~X() {
        std::cout << "~X()\n";
    }
};

class Y {
public:
    Y() {
        std::cout << "Y()\n";
    }
    ~Y() {
        std::cout << "~Y()\n";
    }
};

auto py = new Y; // global definition
void t1() {
    auto px = new (py) X;
    delete px;
    px->~X(); // call dtor
    px = new (py) X;
}
struct B {
    virtual ~B() {
    }
    int j;
    virtual void f() {
        std::cout << "B::f\n";
    }
};

struct D : B {
    void f() {
        std::cout << "D::f\n";
    }
};

void t2() {
    B b;
    b.f(); // B::f
    b.~B();
    new (&b) D; // placement new
    b.f();      // B::f
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
