#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#define BUF_SIZE 1000
#define NUM 4
int times[NUM] = {0, 7, 1, 4};

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
    int numDead;
    pid_t childPid;
    int j;
    setbuf(stdout, NULL);
    for (j = 1; j < NUM; ++j) {
        switch (fork()) {
            case -1:
                fprintf(stderr, "fork\n");
            case 0:
                printf(
                    "[%s] child %d started with PID  %ld, sleeping %d "
                    "seconds\n",
                    currTime("%T"), j, (long)getpid(), times[j]);
                sleep(times[j]);
                _exit(0);
            default:
                break;
        }
    }
    numDead = 0;
    for (;;) {
        childPid = wait(NULL);
        if (childPid == -1) {
            if (errno == ECHILD) {
                printf("No more children -bye!\n");
                exit(0);
            } else {
                fprintf(stderr, "wait\n");
            }
        }
        numDead++;
        printf("[%s] wait() return child PID %ld (numDead=%d)\n",
               currTime("%T"), (long)childPid, numDead);
    }
}
/* [08:09:53] child 2 started with PID  825604, sleeping 1 seconds */
/* [08:09:53] child 1 started with PID  825603, sleeping 7 seconds */
/* [08:09:53] child 3 started with PID  825605, sleeping 4 seconds */
/* [08:09:54] wait() return child PID 825604 (numDead=1) */
/* [08:09:57] wait() return child PID 825605 (numDead=2) */
/* [08:10:00] wait() return child PID 825603 (numDead=3) */
