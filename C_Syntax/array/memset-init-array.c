#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
void t1() {
    long t[5]; // 只能初始化0或-1, 因为0是全0而-1是全1
    memset(t, 0, sizeof(t));
    for (int i = 0; i < 5; ++i) printf("%d\t", t[i]);
    putchar('\n');
    memset(t, -1, sizeof(t));
    for (int i = 0; i < 5; ++i) printf("%d\t", t[i]);
    putchar('\n');
    memset(t, 1, sizeof(t));
    for (int i = 0; i < 5; ++i) printf("%d\t", t[i]);
    putchar('\n');
    // 0   0   0   0   0
    // -1  -1  -1  -1  -1
    // 16843009    16843009    16843009    16843009    16843009
}

void t2() {
    int x[3];
    memset(x, -0x3f, sizeof(x));

    for (int i = 0; i < 3; ++i) {
        assert(x[i] == 0xc1c1c1c1);                            // unsigned
        assert(x[i] == -(INT_MAX - 0xc1c1c1c1 + INT_MAX + 2)); // signed
        // printf("%d=\n", -(INT_MAX - 0xc1c1c1c1 + INT_MAX + 2));
        printf("%d\n", x[i]);
    }
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
}
