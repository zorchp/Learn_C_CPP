#include <stdio.h>
#include <stdlib.h>
#include <gnu/libc-version.h>

int main(int argc, char *argv[]) {
    printf("glibc version=%s\n", gnu_get_libc_version());
    // clang
    /* glibc version=2.31 */
    // gcc
    /* glibc version=2.35 */
    printf("glibc version=%d.%d\n", __GLIBC__, __GLIBC_MINOR__);


    return 0;
}
