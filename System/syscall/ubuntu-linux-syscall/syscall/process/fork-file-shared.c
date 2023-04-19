#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd, flags;
    char template[] = "/tmp/test-XXXXXX";
    setbuf(stdout, NULL);// 无缓冲

    fd = mkstemp(template);
    if (fd == -1) fprintf(stderr, "mkstemp");

    printf("File offset before fork: %lld\n",
           (long long)lseek(fd, 0, SEEK_CUR));

    flags = fcntl(fd, F_GETFL);

    if (flags == -1) fprintf(stderr, "fcntl - F_GETFL");
    printf("O_APPEND flag before fork() is %s\n",
           (flags & O_APPEND) ? "on" : "off");

    switch (fork()) {
        case -1:
            fprintf(stderr, "fork");
        case 0: // child
            if (lseek(fd, 1000, SEEK_SET) == -1) fprintf(stderr, "lseek");
            flags = fcntl(fd, F_GETFL);
            if (flags == -1) fprintf(stderr, "fcntl - F_GETFL");
            flags |= O_APPEND;
            if (fcntl(fd, F_SETFL, flags) == -1)
                fprintf(stderr, "fcntl - F_SETFL");
            _exit(EXIT_SUCCESS);
        default: // parent
            if (wait(NULL) == -1) fprintf(stderr, "wait");
            printf("child has exited\n");

            printf("file offset in parent is %lld\n",
                   (long long)lseek(fd, 0, SEEK_CUR));

            flags = fcntl(fd, F_GETFL);
            if (flags == -1) fprintf(stderr, "fcntl - F_GETFL");

            printf("O_APPEND in parent is %s\n",
                   (flags & O_APPEND) ? "on" : "off");
            exit(EXIT_SUCCESS);
    }
    return 0;
}
/* :!cc fork-file-shared.c && ./a.out */
/* File offset before fork: 0 */
/* O_APPEND flag before fork() is off */
/* child has exited */
/* file offset in parent is 1000 */
/* O_APPEND in parent is on */
