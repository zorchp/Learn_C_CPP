#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int BUF_SIZE = 30;

int main(int argc, char *argv[]) {
    int fds[2];
    char str[] = "who are you?";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    // create new child process
    pid = fork();
    // one direction, parent receive and child send
    if (pid == 0)
        // child process: send msg
        // fds[1]: pipe entrance, send info
        write(fds[1], str, sizeof(str));
    else {
        // parent process: receive msg
        // fds[0]: pipe exit, receive info
        read(fds[0], buf, BUF_SIZE);
        puts(buf);
    }
    return 0;
}
