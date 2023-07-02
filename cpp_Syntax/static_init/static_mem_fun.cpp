#include <iostream>
struct S {
    void f(long) {
        std::cout << "member version\n";
    }

    static void f(int) {
        std::cout << "static member version\n";
    }
};

int main() {
    S s;
    s.f(1);  // static member version
    s.f(1l); // member version
}
