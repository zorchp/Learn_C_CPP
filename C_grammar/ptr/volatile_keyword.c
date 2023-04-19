#include <stdio.h>

int main() {
    // int i = 10;
    volatile int i = 10;
    int a          = i;

    printf("i = %d\n", a);

    // change i but do not let compiler know.
    asm("mov w0,#32");

    int b = i;
    printf("i = %d\n", b);
}
/*
gcc-12(gnu c)
-Og 优化代码
*/