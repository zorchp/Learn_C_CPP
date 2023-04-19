#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
static void sigHandler(int sig) {
    static int count = 0;

    if (sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return; /* Resume execution at point of interruption */
    }

    /* Must be SIGQUIT - print a message and terminate the process */

    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    /* Establish same handler for SIGINT and SIGQUIT. Here we use the
       simpler signal() API to establish a signal handler, but for the
       reasons described in Section 22.7 of TLPI, sigaction() is the
       (strongly) preferred API for this task. */

    if (signal(SIGINT, sigHandler) == SIG_ERR) fprintf(stderr, "signal");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR) fprintf(stderr, "signal");

    for (;;)     /* Loop forever, waiting for signals */
        pause(); /* Block until a signal is caught */
}
