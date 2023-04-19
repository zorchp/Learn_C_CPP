#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char const *argv[]) {
    int *p = sbrk(0);
    int *old = p;
    p = sbrk(MAX * MAX);
    if (p == (void *)(-1)) {
        perror("sbrk");
        exit(EXIT_FAILURE);
    }
    printf("old: \t%p\np:\t%p\n", p, old);
    int *new = sbrk(0);
    printf("new:\t%p\n", new);
    printf("pid=%d\n", getpid());
    // while(1);
    // sleep(-1);
    //      sbrk(-MAX*MAX);
    // use brk free mem:
    int err = brk(old);
    printf("err=%d\n", err); //-1
    // if (-1 == err) {
    //     perror("brk");
    //     exit(EXIT_FAILURE);
    // }
    return 0;
}