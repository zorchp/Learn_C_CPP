#include <stdio.h>

void x1();
void x2();
void x3();

int main(void) {
    printf("%s-%s running...\n", __FILE__, __func__);
    /* x1(); */
    x2();
    x3();
    return 0;
}
