#include <iostream>

using namespace std;
template <typename T>
T max1(T a, T b) {
    return a > b ? a : b;
}
template <typename T>
T max2(T a, T b) {
    return a < b ? b : a;
}

void t1() {
    cout << max1(+0., -0.) << endl;
    cout << max2(+0., -0.) << endl;
    /*
    -0
    0*/
}

void t2() {
    cout << max1(+0, -0) << endl;
    cout << max2(+0, -0) << endl;
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
