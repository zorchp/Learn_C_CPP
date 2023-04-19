#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int s, sig;
    pid_t pid = 702158;
    sig = 13;
    s = kill(pid, sig);

    if (sig) {
        if (s == -1) fprintf(stderr, "kill error\n");
    } else {
        if (s == 0)
            printf("process exists and we can send it a signal\n");
        else {
            switch (errno) {
                case EPERM:
                    printf(
                        "process exists, but we don't have permission to send "
                        "it a signal\n");
                case ESRCH:
                    printf("process does not exist\n");
                default:
                    fprintf(stderr, "kill\n");
            }
        }
    }
    return 0;
}
