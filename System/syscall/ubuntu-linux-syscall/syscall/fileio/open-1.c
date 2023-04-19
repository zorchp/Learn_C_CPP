#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void error_handling(char* msg);

int fd;
void t1() {
    // create and write
    char buf[] = "Let's go!";

    fd = open("data", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) error_handling("open() error");
    printf("file descripter: %d\n", fd);

    if (write(fd, buf, sizeof(buf)) == -1) error_handling("write() error");

    close(fd);
}
void t2() {
    // append to log
    char buf[] = "abc\n";
    fd = open("log", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) error_handling("open() error");
    printf("file descripter: %d\n", fd);

    if (write(fd, buf, sizeof(buf)) == -1) error_handling("write() error");
    close(fd);
}


int main(int argc, char* argv[]) {
    t1();
    t2();
    return 0;
}


void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    /* printf("aa\n"); */
    exit(1);
}
