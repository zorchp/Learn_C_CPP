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

static int p = t1();

int main(int argc, char *argv[]) {
    cout << "main\n";
    return 0;
}
