#include <iostream>

using namespace std;

void t1() {
    int a = 10;
    int &res = a;
    // res = 0;
    // a = 12;
    int c = 19;
    res = c;

    cout << a << endl;
    cout << res << endl;
    cout << c << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}