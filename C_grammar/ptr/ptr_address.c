#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[10];
    printf("sizeof(a)=%lu\n", sizeof a);   // 40
    printf("sizeof(&a)=%lu\n", sizeof &a); // 8:64bit-mach
    printf("a的值为:\t%p\n", a);
    printf("&a的值为:\t%p\n\n", &a);

    printf("a+1的值为:\t%p\n", a + 1);
    printf("&a+1的值为:\t%p\n", &a + 1);
    printf("a+2的值为:\t%p\n", a + 2);
    printf("&a+2的值为:\t%p\n", &a + 2);
    printf("a+3的值为:\t%p\n", a + 3);
    printf("&a+3的值为:\t%p\n", &a + 3);
    /*
    a的值为:   0x16d483060
    &a的值为:  0x16d483060

    a+1的值为: 0x16d483064
    &a+1的值为:    0x16d483088
    */
    return 0;
}