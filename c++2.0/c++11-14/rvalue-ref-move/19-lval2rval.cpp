#include <iostream>
using namespace std;

void t1() {
    int a = 10;
    /* int &&b = a; // error */
    int &&b = std::move(a);
}

void t2() {
    string p = "hello";
    cout << p << endl;
    string &&q = std::move(p);
    cout << p << endl;
    cout << q << endl;
}

int main(int argc, char *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
