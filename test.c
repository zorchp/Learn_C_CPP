#include <stdio.h>
#include <stdlib.h>

void t2() {
    unsigned short a[12] = {0x11, 0x12, 0x13, 0x14, 0x77, 0x88};
    unsigned int* p = (unsigned int)&a[0];
    p++;
    printf("%4x\n", *p); // 140013
}
int main(void) {
    t2();

    return 0;
}
