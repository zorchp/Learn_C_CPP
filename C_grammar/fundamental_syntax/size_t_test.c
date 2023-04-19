#include <stdio.h>

int main() {
    unsigned short a;
    short int b = -1;
    a = b;
    printf("b=%d, ", b);
    printf("a=%d", a);
    // b=-1, a=65535
}