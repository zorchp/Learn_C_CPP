#include <iostream>
// #include <cstdlib> //atexit
using namespace std;


auto f1 = []() { cout << "after main 1\n"; };

void f2(int, void *) { //
    cout << "after main 2\n";
}

struct P {
    ~P() { cout << "after main 3\n"; }
};
P p; // global object

__attribute((destructor)) void after() { //
    cout << "after main 4\n";
}

int main(int argc, char *argv[]) {
    // on_exit(f2, NULL); // just for linux
    atexit(f1); // 调用顺序与注册顺序相反
    cout << "main\n";
    return 0;
}

// main
// after main 1
// after main 2
// after main 3
// after main 4
