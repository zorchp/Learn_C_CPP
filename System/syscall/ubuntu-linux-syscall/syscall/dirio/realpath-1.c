#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
const int BUF_SIZE = 1000;
const char* argv1 = "../a.out";

int main(int argc, char* argv[]) {
    struct stat statbuf;
    char buf[BUF_SIZE];

    if (lstat(argv1, &statbuf) == -1) fprintf(stderr, "lstat error\n");

    if (!S_ISLNK(statbuf.st_mode))
        fprintf(stderr, "%s is not a symbolic link\n", argv1);

    ssize_t numBytes = readlink(argv1, buf, BUF_SIZE - 1);
    if (numBytes == -1) fprintf(stderr, "readlink\n");
    buf[numBytes] = '\0';

    printf("readlink : %s -> %s\n", argv1, buf);
    if (realpath(argv1, buf) == NULL) fprintf(stderr, "realpath error\n");

    printf("realpath=%s -> %s\n", argv1, buf);
    return 0;
}
// ln -s chdir-1.c aa
/* readlink : aa -> chdir-1.c */
/* realpath=aa -> /home/zorch/code/c_cpp_code/syscall/dirio/chdir-1.c */
