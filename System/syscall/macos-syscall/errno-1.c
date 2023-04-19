#include <errno.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    if (EIO == 0) printf("EIO=%d\n", EIO);
    return 0;
}