#include <atomic>
#include <thread>
#include <iostream>

using namespace std;
atomic<int> ai = 0;
atomic<int> aj = 0;
auto f() { return ai++; }

auto g() { return ++aj; }

void t1() {
    cout << f() << endl; // 0
    cout << g() << endl; // 1
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}