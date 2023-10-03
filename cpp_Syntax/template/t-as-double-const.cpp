#include <iostream>
using namespace std;

template <typename T>
void f(const T &x) {
    cout << typeid(T).name() << endl; // i, not const int
    auto y(x);
    cout << y << endl;
}

int main(int argc, char *argv[]) {
    const int x = 10;
    f(x);
    return 0;
}
