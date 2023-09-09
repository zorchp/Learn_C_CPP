#include <stdio.h>
#include <stdlib.h>
void t1() {
    unsigned short a[12] = {0x11, 0x12, 0x13,
                            0x14, 0x77, 0x88}; // 17 18 19 20 119 136
    unsigned int* p = (unsigned int*)&a[0];
    p++;
    // 十六进制, 4 位宽度输出
    printf("%4x\n", *p); // 140013
    // printf("%4x\n", *(p + 1)); // 140013
    // printf("%4x\n", *(p + 2)); // 140013
    // printf("%4x\n", *(p + 3)); // 140013
}

int main(void) {
    t1();

    return 0;
}
