#include <bitset>
#include <iostream>
using namespace std;


void t1() {
    auto bs = bitset<32>(120948);
    cout << bs << '\n';
    cout << bs.to_string() << '\n';
    cout << bs[0] << '\n'; // 0
    cout << bs[2] << '\n'; // 1
    // cout << bs.to_ulong() << '\n';
    cout << bs.flip().to_string() << '\n';
    // cout << bs.flip().to_ulong() << '\n';
    // cout << bs.count() << '\n';
}

void t2() {
    int a = 10;
#ifndef __clang__
    int x = __lg(a);
#else
    int x = bitset<32>(a).to_string().size();
#endif
    cout << x;
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
