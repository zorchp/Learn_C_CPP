#include <iostream>
using namespace std;

void t1() {
    int x{};
    /* int *p = &x++; */
    int *q = &++x;
}

int x = 1;
int get_val() { return x; }
void set_val(int val) {
    int *p = &val;
    x = val;
}

void t2() {
    int y = get_val();
    /* int *p = &get_val(); */
    set_val(5);
}

struct X {
    int a;
};
void t3() {
    cout << X().a << endl;
    /* int b = X().a; */
    /* cout << b << endl; */
}

int main(int argc, char *argv[]) {
    /* t1(); */
    /* t2(); */
    t3();
    return 0;
}
