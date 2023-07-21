#include <iostream>

using namespace std;

void t1() {
    auto f1 = [](float f) { return f == 0; };
    auto f2 = [](float f) { return abs(f) < 0.000001f; };
    cout << f1(0.0f);
    cout << f2(0.0f);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
