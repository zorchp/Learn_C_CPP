#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char tmp[] = "/tmp/test-XXXXXX";
    int fd = mkstemp(tmp);
    int flags, accseeMode;

    flags = fcntl(fd, F_GETFL);
    if (flags == -1) fprintf(stderr, "fcntl\n");

    // 判断访问模式: 是否同步模式
    if (flags & O_SYNC) printf("writes are synchronized\n");

    // 判断状态标志
    accseeMode = flags & O_ACCMODE;
    if (accseeMode == O_WRONLY || accseeMode == O_RDWR)
        printf("file is writable\n");

    /* file is writable */

    unlink(tmp);
    close(fd);
    return 0;
}
