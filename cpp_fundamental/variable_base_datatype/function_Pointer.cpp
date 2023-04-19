#include <iostream>

using namespace std;

int Gcd(int x, int y) {
    int z = x;
    if (x > y) { z = y; }
    for (int i = z; i >= 1; i--)
        if (x % i == 0 && y % i == 0) return i;
    return 0;
}

int Lcm(int x, int y) {
    for (int i = 1; i <= x; ++i) {
        if (i * y % x == 0) { return i * y; }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int a, b;
    // 声明函数指针
    int (*pf)(int, int);

    cout << "Input a and b: " << endl;
    cin >> a >> b;

    pf = Gcd;
    cout << "Gcd is: " << pf(a, b) << endl;

    pf = Lcm;
    cout << "Lcm is: " << pf(a, b) << endl;

    return 0;
}