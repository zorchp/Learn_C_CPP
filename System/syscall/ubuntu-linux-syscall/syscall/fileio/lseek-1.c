#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void t1() {
    int fd = open("data", O_WRONLY, S_IWUSR);
    int cur = lseek(fd, 0, SEEK_CUR);
    printf("cur seek = %d\n", cur);
    cur = lseek(fd, 2, SEEK_SET);
    printf("cur seek = %d\n", cur);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
