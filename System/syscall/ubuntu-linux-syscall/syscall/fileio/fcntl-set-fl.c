#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char tmp[] = "/tmp/test-XXXXXX";
    int fd = mkstemp(tmp);
    int flags;

    flags = fcntl(fd, F_SETFL);
    if (flags == -1) fprintf(stderr, "fcntl\n");

    flags |= O_APPEND;
    // 更新状态标志
    if (fcntl(fd, F_SETFL, flags) == -1) fprintf(stderr, "fcntl F_SETFL");

    if (flags & O_APPEND) printf("file can be appended\n");

    /* file can be appended */

    unlink(tmp);
    close(fd);
    return 0;
}
