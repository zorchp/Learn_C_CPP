#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    char *ptr;
    size_t size = 100;
    ptr = (char *)malloc(size);
    chdir("/usr/local/lib");

    getcwd(ptr, size);
    printf("cwd = %s\n", ptr); // cwd = /usr/local/lib

    return 0;
}
