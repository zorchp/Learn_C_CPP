#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int status;
    pid_t pid = fork();

    if (pid == 0)
        return 3;
    else {
        printf("child process's pid is %d \n", pid);
        pid = fork();
        if (pid == 0)
            exit(7);
        else {
            printf("child pid is: %d\n", pid);
            wait(&status);
            if (WIFEXITED(status))
                printf("child send one :%d \n", WEXITSTATUS(status));

            wait(&status);
            if (WIFEXITED(status))
                printf("child send two :%d \n", WEXITSTATUS(status));

            sleep(30);
        }
    }

    return 0;
}
/* child process's pid is 89410  */
/* child pid is: 89411 */
/* child send one :3  */
/* child send two :7  */

/* hep              89135   0.0  0.0        0      0 s000  Z+   11:26下午
 * 0:00.00 (wait.out) */
/* hep              89133   0.0  0.0 408497216   1424 s000  S+   11:26下午
 * 0:00.00 ./wait.out */
