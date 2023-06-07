#include <iostream>
using namespace std;

__attribute((constructor)) void before() { //
    cout << "before main 1\n";
}

int a = []() {
    cout << "before main 2\n";
    return 0;
}();

int t1() {
    cout << "before main 3\n";
    return 1;
}

static int p1 = t1();

struct P {
    P() { cout << "before main 4\n"; }
};
P p; // global object

int main(int argc, char *argv[]) {
    cout << "main\n";
    return 0;
}
// before main 1
// before main 2
// before main 3
// before main 4
// main
