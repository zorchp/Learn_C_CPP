#include <iostream>
#include <format>

using namespace std;
using FUNC = int (*)();

void t1() {
    FUNC a = [] { return 1; };
    cout << format("a = {}\n", a());
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
