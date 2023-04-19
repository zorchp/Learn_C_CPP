#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gval = 10;

int main(int argc, char *argv[]) {
    pid_t pid;
    int lval = 20;
    gval++, lval += 5;

    pid = fork();
    if (pid == 0)
        gval += 2, lval += 2;
    else
        gval -= 2, lval -= 2;
    if (pid == 0)
        printf("child proc: [%d, %d] \n", gval, lval);
    else
        printf("Parent proc: [%d, %d] \n", gval, lval);

    /* Parent proc: [9, 23]  */
    /* child proc: [13, 27]  */
    return 0;
}
