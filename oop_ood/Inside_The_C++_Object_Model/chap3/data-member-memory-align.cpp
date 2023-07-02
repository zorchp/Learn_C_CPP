#include <bits/stdc++.h>
using namespace std;
struct P {
    char c;
    int x;
};

void t1() {
    P p;
    p.c = 'a';
    p.x = 10;
    printf("%p\n", &p);
    printf("%p\n", &p.c);
    printf("%p\n", &p.x);
    // 0x16b97e760
    // 0x16b97e760
    // 0x16b97e764

    for (int i{}; i < 5; ++i) {
        printf("%d\n", *(char *)((long)&p + i));
    }
    // 97
    // -89
    // 114
    // 109
    // 10
    // padding 3bytes
}

int main(int argc, char *argv[]) {
    //
    t1();
    return 0;
}