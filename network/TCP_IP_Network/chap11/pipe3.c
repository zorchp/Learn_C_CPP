#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int BUF_SIZE = 30;

int main(int argc, char *argv[]) {
    int fds1[2], fds2[2];
    char str1[] = "who are you?";
    char str2[] = "thank you for your msg~";
    char buf[BUF_SIZE];
    pid_t pid;

    // create 2 pipes
    pipe(fds1), pipe(fds2);
    // create new child process
    pid = fork();
    // one direction, parent receive and child send
    if (pid == 0) {
        // child process: send msg
        // fds1[1]: pipe entrance, send info
        write(fds1[1], str1, sizeof(str1));
        /* sleep(2); */
        read(fds2[0], buf, BUF_SIZE);
        printf("child proc output: %s \n", buf);
    } else {
        // parent process: receive msg
        // fds1[0]: pipe exit, receive info
        read(fds1[0], buf, BUF_SIZE);
        printf("parent proc output: %s \n", buf);
        write(fds2[1], str2, sizeof(str2));
        sleep(3);
    }
    return 0;
}
