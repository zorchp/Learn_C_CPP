#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int BUF_SIZE = 30;

int main(int argc, char *argv[]) {
    int fds[2];
    char str1[] = "who are you?";
    char str2[] = "thank you for your msg~";
    char buf[BUF_SIZE];
    pid_t pid;

    // create a pipe
    pipe(fds);
    // create new child process
    pid = fork();
    // one direction, parent receive and child send
    if (pid == 0) {
        // child process: send msg
        // fds[1]: pipe entrance, send info
        write(fds[1], str1, sizeof(str1));
        /* sleep(2); */
        read(fds[0], buf, BUF_SIZE);
        printf("child proc output: %s \n", buf);
    } else {
        // parent process: receive msg
        // fds[0]: pipe exit, receive info
        read(fds[0], buf, BUF_SIZE);
        printf("parent proc output: %s \n", buf);
        write(fds[1], str2, sizeof(str2));
        sleep(3);
    }
    return 0;
}

/* parent proc output: who are you?  */
/* child proc output: thank you for your msg~  */
/* ./pipe2.out  0.00s user 0.00s system 0% cpu 3.007 total */
