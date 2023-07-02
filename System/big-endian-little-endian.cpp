#include <cstdio>
#include <cassert>
using namespace std;

void t1() {
    int x = 0x6261;
    // char* s = reinterpret_cast<char*>(&x);
    char* s = (char*)&x;
    assert((void*)s == &x);
    printf("%s\n", s); // ab, little-endian
}

void t2() { // simplify
    int x = 0x0102;
    char* s = reinterpret_cast<char*>(&x);
    printf("%s-endian\n", s[0] == '\x1' ? "big" : "little");
}

void t3() {
    union P { // just store one part memory
        int a;
        char c[sizeof(a)];
    };
    P p{.a = 0x0102};
    // printf("%s\n", p.c);
    printf("%s-endian\n", p.c[0] == '\x1' ? "big" : "little");
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    t3();
    return 0;
}