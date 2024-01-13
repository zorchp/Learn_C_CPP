#include <iostream>

class Foo {
public:
    Foo() { display(); }

    virtual void display() { std::cout << "hello foo!" << std::endl; }

    virtual ~Foo() {}
};

class Bar : public Foo {
public:
    void display() { std::cout << "hello bar!" << std::endl; }

    virtual ~Bar() {}
};

int main() {
    Foo *f = new Bar();
    delete f; // hello foo!
}
