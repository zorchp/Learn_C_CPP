#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>

// void error_handling(char* msg) {
//     fputs(msg, stderr);
//     fputc('\n', stderr);
//     exit(1);
// }

int main(int argc, char* argv[]) {

    // void t1() {
    int fd;
    char buf[] = "Let's go!";

    fd = open("a-data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    // if (fd == -1) error_handling("open() error");
    printf("file descripter: %d\n", fd);
    write(fd, buf, sizeof(buf));
    // if (write(fd, buf, sizeof(buf)) == -1)
    // error_handling("write() error");
    close(fd);
    // }

    // int main(int argc, char* argv[]) {
    // t1();
    return 0;
}
