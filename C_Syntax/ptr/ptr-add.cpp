#include <cstdio>

void t1() {
    short* ptr = (short*)0xffed1200;
    ptr++;
    printf("%p\n", ptr); // 0xffed1202
}

void t2() {
    short x = 12;
    auto px = &x;
    printf("%p\n", px); // 0x16bac28a0
    px++;
    printf("%p\n", px); // 0x16bac28a2
}

int main() {
    t1();
    // t2();
}
