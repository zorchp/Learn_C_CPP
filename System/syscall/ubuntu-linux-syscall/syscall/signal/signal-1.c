#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigHandler(int sig) { printf("Ouch!\n"); }

int main(int argc, char *argv[]) {
    int j;
    if (signal(SIGINT, sigHandler) == SIG_ERR) fprintf(stderr, "signal\n");
    for (j = 0;; ++j) {
        printf("%d\n", j);
        sleep(3);
    }
    return 0;
}
