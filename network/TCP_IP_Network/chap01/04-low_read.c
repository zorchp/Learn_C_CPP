#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
const int BUF_SIZE = 100;

void error_handling(char* msg);
int main(int argc, char* argv[]) {
    int fd;
    char buf[BUF_SIZE];

    fd = open("data.txt", O_RDONLY);
    if (fd == -1) error_handling("open() error");
    printf("file descripter: %d\n", fd);

    if (read(fd, buf, sizeof(buf)) == -1) error_handling("read() error");
    printf("file data: %s\n", buf);
    close(fd);
    return 0;
}


void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
