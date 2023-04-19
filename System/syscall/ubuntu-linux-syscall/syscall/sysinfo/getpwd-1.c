#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    size_t size = 100;
    char *ptr = (char *)malloc(size);
    /* chdir("/usr/bin/"); */

    getcwd(ptr, size);
    printf("cwd = %s\n", ptr);
    return 0;
}
