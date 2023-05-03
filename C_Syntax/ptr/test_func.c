#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* f1(int a) {
    /* static char pp[20]; */
    /* char* pp = malloc(20); */
    static char* pp;
    char *c1 = "123", *c2 = "456";
    if (a) {
        /* pp = "123"; */
        strcpy(pp, c1);
    } else {
        strcpy(pp, c2);
    }
    return pp;
}
int main(int argc, char* argv[]) {
    char* p;
    p = f1(1);
    printf("%s", p);
    f1(0);
    printf("%s", p);
    return 0;
}
