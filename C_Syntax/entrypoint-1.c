#include <stdio.h>
#include <stdlib.h>

int test() {
    printf("test work\n");
    exit(0);
}

int main() {
    printf("not work\n");
    return 0;
}
