#include <iostream>
using namespace std;


int f(int) {
    cout << __func__ << endl;
    return 0;
}

void f(double) { cout << __func__ << endl; }

void t1() {
    f(1);
    f(1.);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
