#include <bits/stdc++.h>
using namespace std;
struct P {
    int x{12};
    long y{13};
};

void t1() {
    P p;
    int* px = reinterpret_cast<int*>(&p);
    assert((void*)&p == px);
    cout << *px << endl; // 12
    long* py = reinterpret_cast<long*>((P*)((long)&p + sizeof(long)));
    // aligned : 8 bytes
    cout << *py << endl; // 13
}


int main(int argc, char const* argv[]) {
    t1();
    return 0;
}