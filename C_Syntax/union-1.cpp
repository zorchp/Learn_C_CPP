#include <cstdio>
#include <cstring>
#include <iostream>
union P {
    int x;
    char s[4];
    float f;
    P() { std::cout << "union P();\n"; }
};

void t1() {
    P p;
    char tmp[] = "abc";
    memcpy(p.s, tmp, 3);
    p.f = 1.9;
    p.x = 12;
    // printf("%s,%f,%d\n", p.s, p.f, p.x);
    // printf("%s\n", p.s);
    printf("%f\n", p.f);
    printf("%d\n", p.x);
}


void t2() {
    //
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}
