#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

void t1() {
    cout << Max(1, 2) << endl;
    cout << Max<>(1, 2) << endl;
    // cout << Max(1.9, 2) << endl;
    cout << Max<int>(1.0, 2) << endl;
    cout << Max<double>(1.9, 2) << endl;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
