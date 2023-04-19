#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
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
    return 0;
}