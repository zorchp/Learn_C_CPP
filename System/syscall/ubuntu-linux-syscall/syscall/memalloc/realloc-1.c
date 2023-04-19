#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

const int NUM = 10;
int main(int argc, char *argv[]) {
    int *p = (int *)malloc(NUM * sizeof(int));
    memset(p, 1, sizeof(int) * NUM);
    printf("p=%p\n", p);
    printf("sizeof(p)=%lu\n", malloc_usable_size(p));

    int *np = realloc(p, 3);
    if (np == NULL) {
        fprintf(stderr, "realloc error\n");
        exit(1);
    } else
        p = np;
    printf("sizeof(np)=%lu\n", malloc_usable_size(np));
    printf("np=%p\n", np);

/* p=0x16a52a0 */
/* sizeof(p)=40 */
/* sizeof(np)=40 */
/* np=0x16a52a0 */

    return 0;
}
