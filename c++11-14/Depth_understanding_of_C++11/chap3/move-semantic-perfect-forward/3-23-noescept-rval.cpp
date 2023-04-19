#include <iostream>
#include <utility>
using namespace std;
struct Maythrow {
    Maythrow() {}
    Maythrow(const Maythrow&) {
        std::cout << "Maythorow copy constructor." << endl;
    }
    Maythrow(Maythrow&&) { std::cout << "Maythorow move constructor." << endl; }
};
struct Nothrow {
    Nothrow() {}
    Nothrow(Nothrow&&) noexcept {
        std::cout << "Nothorow move constructor." << endl;
    }
    Nothrow(const Nothrow&) {
        std::cout << "Nothorow move constructor." << endl;
    }
};
int main() {
    Maythrow m;
    Nothrow n;
    Maythrow mt = move_if_noexcept(m); // Maythorow copy constructor.
    Nothrow nt = move_if_noexcept(n);  // Nothorow move constructor.
    return 0;
}
// 编译选项:g++ -std=c++11 3-3-8.cpp

