#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *p = (int *)malloc(32);
    free(p);
    return 0;
}
