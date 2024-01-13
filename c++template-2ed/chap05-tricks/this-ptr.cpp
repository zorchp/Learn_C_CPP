#include <iostream>

template <typename T>
class B {
public:
    void exit() { std::cout << "exit\n"; }
};

template <typename T>
class D : B<T> {
public:
    void foo() {
        // exit(); // error
        // error: there are no arguments to 'exit' that depend on a template
        // parameter, so a declaration of 'exit' must be available
        // [-fpermissive]
        this->exit(); // ok
        B<T>::exit(); // ok
    }
};

int main(int argc, char *argv[]) {
    D<int>().foo();
    return 0;
}
