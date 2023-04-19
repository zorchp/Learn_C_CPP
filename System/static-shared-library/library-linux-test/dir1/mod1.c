#include <stdio.h>
void x2();

void x1() {
    printf("%s-%s running...\n", __FILE__, __func__);
    x2();
}
