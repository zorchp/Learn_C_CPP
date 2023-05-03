#include <iostream>
#include <vector>
#include <string>
using namespace std;

[[noreturn]] //attribute tag
int t1() {
    // return 1;
    throw std::runtime_error("xxx"); //
}


void t2() {
    [[gnu::unused]] int a;
    int b = 1;
    cout << b;
}

int main(int argc, char const* argv[]) {
    // cout << t1();
    t2();
    return 0;
}
