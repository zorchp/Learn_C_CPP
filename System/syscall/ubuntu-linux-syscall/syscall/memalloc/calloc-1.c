#include <stdio.h>
#include <stdlib.h>

struct {
    int age;
    char *name;
} P;
int main(int argc, char *argv[]) {
    struct P *p = NULL;
    printf("p=%p\n", p);
    p = calloc(1000, sizeof(P));
    if (p == NULL) fprintf(stderr, "calloc error\n");
    return 0;
}
