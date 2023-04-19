#include <stdio.h>

int main() {
    int a;
    int *ptr = &a;
    ptr      = NULL;

    printf("ptr 的地址是 %p\n", ptr);

    return 0;
}