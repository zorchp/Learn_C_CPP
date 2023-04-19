#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void read_childproc(int sig) {
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);

    if (WIFEXITED(status)) {
        printf("removed proc id: %d\n", id);
        printf("child send: %d\n", WEXITSTATUS(status));
    }
}

int main(int argc, char *argv[]) {
    pid_t pid;
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    pid = fork();
    if (pid == 0) {
        puts("hi I'm child process 1");
        sleep(10);
        return 12;
    } else {
        printf("child proc id: %d \n", pid);
        pid = fork();
        if (pid == 0) {
            puts("hi I'm child process 2");
            sleep(10);
            return 24;
        } else {
            int i;
            printf("child proc id: %d \n", pid);
            for (i = 0; i < 5; i++) {
                puts("wait...");
                sleep(5);
            }
        }
    }
    return 0;
}

/* child proc id: 4513  */
/* hi I'm child process 1 */
/* child proc id: 4514  */
/* wait... */
/* hi I'm child process 2 */
/* wait... */
/* removed proc id: 4514 */
/* child send: 24 */
/* wait... */
/* wait... */
/* wait... */
/* ./remove_zombie.out  0.00s user 0.00s system 0% cpu 25.020 total */
