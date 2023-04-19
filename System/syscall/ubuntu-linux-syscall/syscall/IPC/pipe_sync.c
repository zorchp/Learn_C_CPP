#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1000
#define NUM 4
int times[NUM] = {0, 4, 2, 6};

char *currTime(const char *format) {
    static char buf[BUF_SIZE]; /* Nonreentrant */
    struct tm *tm;

    time_t t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL) return NULL;
    size_t s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);

    return (s == 0) ? NULL : buf;
}

// 父进程与多个子进程同步, 通过pipe,
// 可以协调一个进程的动作使之与多个其他相关进程匹配.
// 而多个信号无法排队导致信号不适用于这种情形
// 信号的优势在于可以被一个进程广播到进程组中的所有成员
int main(int argc, char *argv[]) {
    int pfd[2]; /* Process synchronization pipe */
    int j, dummy;


    setbuf(stdout, NULL); /* Make stdout unbuffered, since we
                             terminate child with _exit() */
    printf("%s  Parent started\n", currTime("%T"));

    if (pipe(pfd) == -1) fprintf(stderr, "pipe");

    for (j = 1; j < NUM; j++) {
        switch (fork()) {
            case -1:
                fprintf(stderr, "fork %d", j);

            case 0:                      /* Child */
                if (close(pfd[0]) == -1) /* Read end is unused */
                    fprintf(stderr, "close");

                /* Child does some work, and lets parent know it's done */

                sleep(times[j]);
                /* Simulate processing */
                printf("%s  Child %d (PID=%ld) closing pipe\n", currTime("%T"),
                       j, (long)getpid());
                if (close(pfd[1]) == -1) fprintf(stderr, "close");

                /* Child now carries on to do other things... */

                _exit(EXIT_SUCCESS);

            default: /* Parent loops to create next child */
                break;
        }
    }

    /* Parent comes here; close write end of pipe so we can see EOF */

    if (close(pfd[1]) == -1) /* Write end is unused */
        fprintf(stderr, "close");

    /* Parent may do other work, then synchronizes with children */

    if (read(pfd[0], &dummy, 1) != 0) fprintf(stderr, "parent didn't get EOF");
    printf("%s  Parent ready to go\n", currTime("%T"));

    /* Parent can now carry on to do other things... */

    exit(EXIT_SUCCESS);
    /* 16:54:19  Parent started */
    /* 16:54:21  Child 2 (PID=1662829) closing pipe */
    /* 16:54:23  Child 1 (PID=1662828) closing pipe */
    /* 16:54:25  Child 3 (PID=1662830) closing pipe */
    /* 16:54:25  Parent ready to go */
}
