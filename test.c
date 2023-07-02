#include <stdio.h>
#include <stdlib.h>
int main(void) {
    printf("main addr: %p\n", (void *)main);

    int a = 1;
    printf("stack addr: %p\n", &a);

    int *p = (int *)malloc(sizeof(int));
    printf("heap addr: %p\n", p);
    free(p);
    /*
    main addr: 0x102257ee4
    stack addr: 0x16dbaab24
    heap addr: 0x600002c28050
    */

    return 0;
}
