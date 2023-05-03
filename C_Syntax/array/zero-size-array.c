#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void t1() {
    int a[0];
    memset(a, 0, sizeof(a));
    printf("%d\n", a[0]); // 1865871392
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}