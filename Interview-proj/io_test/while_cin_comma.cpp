#include <iostream>
#include <unistd.h>
using namespace std;

int main(void) {
    // int n;
    // while (cin >> n, n > 0) { cout << n << endl; }
    int a{}, b{};
    while (a == 10, b == a) {
        if (b < 0) break;
        b--;
        cout << a << " " << b << endl;
        sleep(1);
    }
    return 0;
}