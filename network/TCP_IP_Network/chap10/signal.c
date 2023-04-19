#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void timeout(int sig) {
    if (sig == SIGALRM) puts("timeout!");
    alarm(2);
}

void keyControl(int sig) {
    if (sig == SIGINT) puts("CTRL+C pressed");
}

int main(int argc, char *argv[]) {
    int i;
    signal(SIGALRM, timeout);
    signal(SIGINT, keyControl);
    alarm(2);
    for (i = 0; i < 3; i++) {
        puts("wait..");
        sleep(100);
    }
    return 0;
}
/* wait.. */
/* timeout! */
/* wait.. */
/* timeout! */
/* wait.. */
/* ^CCTRL+C pressed */
