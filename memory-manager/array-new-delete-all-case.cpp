#include <bits/stdc++.h>
using namespace std;


void t11() {
    int* p = new int[4];
    // 赋值
    for (int i{}; i < 4; ++i) {
        p[i] = i + 1;
    }
    printf("addr: %p\n", &p);
    for (int i{}; i < 4; ++i) {
        printf("%d\n", *(p + i));
    }
    delete p;
    printf("addr: %p\n", &p);
    for (int i{}; i < 4; ++i) {
        printf("%d\n", *(p + i));
    }
    // addr: 0x16bb2abf8
    // 1
    // 2
    // 3
    // 4
    // addr: 0x16bb2abf8
    // 1273102416
    // 12287
    // 2043
    // 0
}

void t12() {
    using namespace std::complex_literals;
    complex<int>* p = new complex<int>[3];
    p[0] = 1i;
    p[1] = 2;
    p[2] = 3;
    for (int i{}; i < 3; ++i) {
        cout << *(p + i) << endl;
    }
    delete p;
    for (int i{}; i < 3; ++i) {
        cout << *(p + i) << endl;
    }
    // (0,1)
    // (2,0)
    // (3,0)
    // (-1825926720,37415)
    // (2043,0)
    // (2700593,0)
}

void t21() {
    vector<int>* p = new vector<int>[3];
    p[0] = vector<int>{1, 2};
    p[1] = vector<int>{1, 2};
    p[2] = vector<int>{1, 2};
    for (int i{}; i < 3; ++i) {
        for (auto j : p[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    printf("%p\n", p);
    delete p;
    // printf("%p\n", p);
    // for (int i{}; i < 3; ++i) {
    //     for (auto j : p[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // 1 2
    // 1 2
    // 1 2
    // 0x600002818130
    // a.out(28303,0x1f8a75e00) malloc: *** error for object 0x600002818130:
    // pointer being freed was not allocated a.out(28303,0x1f8a75e00) malloc:
    // *** set a breakpoint in malloc_error_break to debug zsh: abort ./a.out
}

class P {
    int i{};

public:
    P() { cout << "P()\n"; }
    P(int x) : i(x) { cout << "P(int)\n"; }
    P(const P&) { cout << "P(const P&)\n"; }
    operator int() { // for cast
        return i;
    }
    ~P() { cout << "~P()\n"; }
};

void t22() {
    P* p = new P[3];
    p[0] = P(0);
    p[1] = P(1);
    p[2] = P(2);
    for (int i{}; i < 3; ++i) cout << p[i] << endl;
    delete p;
    for (int i{}; i < 3; ++i) cout << p[i] << endl;
    // P()
    // P()
    // P()
    // P(int)
    // ~P()
    // P(int)
    // ~P()
    // P(int)
    // ~P()
    // 0
    // 1
    // 2
    // ~P()
    // array-new-delete-all-case.out(54082,0x1f8a75e00) malloc: *** error for
    // object 0x6000033e8008: pointer being freed was not allocated
    // array-new-delete-all-case.out(54082,0x1f8a75e00) malloc: *** set a
    // breakpoint in malloc_error_break to debug
}
int main(int argc, char* argv[]) {
    // t11();
    // t12();
    // t21();
    t22();
    return 0;
}
