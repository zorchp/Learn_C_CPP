#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void print(int i) {
    if (i == SIGALRM) printf("%d\n", i);
    int alm = alarm(3);
    printf("alm=%d\n", alm);
}

int main(int argc, char *argv[]) {
    /* int i; */
    signal(SIGALRM, print);
    alarm(3);
    sleep(10);
    /* i = alarm(2); */
    /* printf("alarm: %d\n", i); */
    signal(SIGALRM, print);
    return 0;
}
