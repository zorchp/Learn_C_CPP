#include <stdio.h>
#include <stdlib.h>


void exceptionExample() {
    int *pi = NULL;
    try { // try-finally: only in Microsoft
        pi  = (int *)malloc(sizeof(int));
        *pi = 5;
        printf("%d\n", *pi);
    } finally { free(pi); }
}

int main(int argc, char const *argv[]) {
    exceptionExample();
    return 0;
}