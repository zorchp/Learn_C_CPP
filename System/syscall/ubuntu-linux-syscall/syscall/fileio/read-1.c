#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void t1() {
    int fd = open("data", O_RDONLY);
    char buf[100];
    read(fd, buf, 10);
    buf[11] = '\0';
    printf("buf=%s\n", buf); // buf=Let's go!

    close(fd);
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
