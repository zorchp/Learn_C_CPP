#include <iostream>
#include <array>

using namespace std;

void t1() {
    cout << sizeof(array<int, 0>{}); // 4
    cout << sizeof(array<int, 3>{}); // 12
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
