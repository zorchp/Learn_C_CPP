#include <stdio.h>

int main(int argc, char const *argv[]) {
    int *a = (void *)0;
    printf("%p,%p\n", a, &a);
    int *b = (void *)1;
    printf("%p,%p\n", b, &b);
    printf("a==b: %d\n", a == b);
    return 0;
}