#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>

#define BUF_SIZE 1000

#define SYNC_SIG SIGUSR1 /* Synchronization signal */

static void /* Signal handler - does nothing but return */
handler(int sig) {}

char *currTime(const char *format) {
    static char buf[BUF_SIZE]; /* Nonreentrant */
    time_t t;
    size_t s;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL) return NULL;

    s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

    return (s == 0) ? NULL : buf;
}

int main(int argc, char *argv[]) {
    pid_t childPid;
    sigset_t blockMask, origMask, emptyMask;
    struct sigaction sa;

    setbuf(stdout, NULL); /* Disable buffering of stdout */

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SYNC_SIG); /* Block signal */
    if (sigprocmask(SIG_BLOCK, &blockMask, &origMask) == -1)
        fprintf(stderr, "sigprocmask");

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = handler;
    if (sigaction(SYNC_SIG, &sa, NULL) == -1) fprintf(stderr, "sigaction");

    switch (childPid = fork()) {
        case -1:
            fprintf(stderr, "fork");

        case 0: /* Child */

            /* Child does some required action here... */

            printf("[%s %ld] Child started - doing some work\n", currTime("%T"),
                   (long)getpid());
            sleep(2); /* Simulate time spent doing some work */

            /* And then signals parent that it's done */

            printf("[%s %ld] Child about to signal parent\n", currTime("%T"),
                   (long)getpid());
            if (kill(getppid(), SYNC_SIG) == -1) fprintf(stderr, "kill");

            /* Now child can do other things... */

            _exit(EXIT_SUCCESS);

        default: /* Parent */

            /* Parent may do some work here, and then waits for child to
               complete the required action */

            printf("[%s %ld] Parent about to wait for signal\n", currTime("%T"),
                   (long)getpid());
            sigemptyset(&emptyMask);
            if (sigsuspend(&emptyMask) == -1 && errno != EINTR)
                fprintf(stderr, "sigsuspend");
            printf("[%s %ld] Parent got signal\n", currTime("%T"),
                   (long)getpid());

            /* If required, return signal mask to its original state */

            if (sigprocmask(SIG_SETMASK, &origMask, NULL) == -1)
                fprintf(stderr, "sigprocmask");

            /* Parent carries on to do other things... */

            exit(EXIT_SUCCESS);
    }
}

/* :!cc fork-sig-sync.c -Wall && ./a.out */
/* [20:01:11 742971] Parent about to wait for signal */
/* [20:01:11 742977] Child started - doing some work */
/* [20:01:13 742977] Child about to signal parent */
/* [20:01:13 742971] Parent got signal */
