#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork
static int idata = 111;

int main(int argc, char *argv[]) {
    pid_t childPId;
    int istack = 222;

    switch (childPId = fork()) {
        case -1:
            fprintf(stderr, "fork error\n");
        case 0:
            idata *= 3;
            istack *= 3;
            break;
        default:
            sleep(3);
            break;
    }

    printf("PID=%ld %s idata=%d istack=%d\n", (long)getpid(),
           (childPId == 0) ? "(child) " : "(parent)", idata, istack);
    /* PID=526436 (child)  idata=333 istack=666 */
    /* PID=526435 (parent) idata=111 istack=222 */

    return 0;
}
