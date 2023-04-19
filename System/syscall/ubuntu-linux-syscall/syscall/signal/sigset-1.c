#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


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

// 显示进程的信号掩码
int printSigMask(FILE *of, const char *msg) {
    sigset_t currMask;
    if (msg != NULL) fprintf(of, "%s\n", msg);

    // 显式向信号掩码添加或移除信号, 修改或获取信号掩码
    if (sigprocmask(SIG_BLOCK, NULL, &currMask) == -1) return -1;
    printSigset(of, "\t\t", &currMask);
    return 0;
}

// 显示当前处于等待状态的信号集
int printPendingSigs(FILE *of, const char *msg) {
    sigset_t pendingSigs;
    if (msg != NULL) fprintf(of, "%s\n", msg);

    if (sigpending(&pendingSigs) == -1) return -1;
    printSigset(of, "\t\t", &pendingSigs);
    return 0;
}

void t1() {
    sigset_t set;
    printSigset(stdout, "prefix ", &set); // prefix <empty signal set>
    sigaddset(&set, SIGKILL);
    printSigset(stdout, "prefix ", &set); // prefix 9 (Killed)
    printf("-------------\n");
    sigaddset(&set, SIGKILL);
    printSigset(stdout, "prefix ", &set);
    /* prefix 9 (Killed) */
    /* prefix 13 (Broken pipe) */
}

void t2() {
    sigset_t set;
    sigaddset(&set, SIGKILL);
    printSigMask(stdout, NULL); //                <empty signal set>
}

void t3() {
    sigset_t blockSet, prevMask;
    sigemptyset(&blockSet);
    sigaddset(&blockSet, SIGINT);

    if (sigprocmask(SIG_BLOCK, &blockSet, &prevMask) == -1) {
        fprintf(stderr, "sigprocmask1\n");
        exit(1);
    }

    if (sigprocmask(SIG_SETMASK, &prevMask, NULL) == -1) {
        fprintf(stderr, "sigprocmask2\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    // test
    t1();
    /* t2(); */
    /* t3(); */
    return 0;
}
