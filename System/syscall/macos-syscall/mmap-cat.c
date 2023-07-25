#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *addr;
    int fd;
    struct stat sb;

    char fname[] = "memcat.c";
    fd = open(fname, O_RDONLY);
    assert(fd != -1);

    assert(fstat(fd, &sb) != -1);
    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    assert(addr != MAP_FAILED);
    assert(write(STDOUT_FILENO, addr, sb.st_size) == sb.st_size);
    return 0;
}
