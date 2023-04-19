#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
const int NUMSECS = 15;

static int sigCnt[NSIG];
static volatile sig_atomic_t gotSigint = 0;

void printSigset(FILE *of, const char *prefix, const sigset_t *sigset) {
    int sig, cnt;
    cnt = 0;
    for (sig = 1; sig < NSIG; ++sig) {
        if (sigismember(sigset, sig)) {
            ++cnt;
            fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
        }
    }

    if (cnt == 0) fprintf(of, "%s<empty signal set>\n", prefix);
}
static void handler(int sig) {
    if (sig == SIGINT)
        gotSigint = 1;
    else
        sigCnt[sig]++;
}

int main(int argc, char *argv[]) {
    int n, numSecs;
    sigset_t pendingMask, blockingMask, emptyMask;

    printf("%s: PID is %ld\n", argv[0], (long)getpid());

    for (n = 1; n < NSIG; ++n) (void)signal(n, handler);

    if (numSecs) {
        numSecs = NUMSECS;
        sigfillset(&blockingMask);
        if (sigprocmask(SIG_SETMASK, &blockingMask, NULL) == -1) exit(-1);

        printf("%s sleeping for %d secs \n", argv[0], numSecs);
        sleep(numSecs);

        if (sigpending(&pendingMask) == -1) exit(-1);

        printf("%s pending signal are: \n", argv[0]);
        printSigset(stdout, "\t\t", &pendingMask);

        sigemptyset(&emptyMask);
        if (sigprocmask(SIG_SETMASK, &emptyMask, NULL) == -1) exit(1);
    }

    while (!gotSigint) continue;

    for (n = 1; n < NSIG; ++n)
        if (sigCnt[n])
            printf("%s: signal %d caught %d times %s \n", argv[0], n, sigCnt[n],
                   (sigCnt[n] == 1) ? "" : "s");
    return 0;
}
