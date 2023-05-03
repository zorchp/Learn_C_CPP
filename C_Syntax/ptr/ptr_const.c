#include <stdio.h>

int main(int argc, char const* argv[]) {
    int ss = 9;
    int* const r = &ss; //指针常量(指针类型的常量)
    printf("r=%p\n", r);
    printf("*r=%d\n", *r);
    printf("ss=%d\n", ss);
    *r = 100;
    printf("&ss=%p\n", &ss);
    printf("*r=%d\n", *r);
    printf("ss=%d\n", ss);
    return 0;
    /*
r=0x16b1d70dc
*r=9
ss=9
&ss=0x16b1d70dc
*r=100
ss=100
        */
}