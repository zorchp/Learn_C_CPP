#include <stdio.h>

int main(int argc, char const *argv[]) {
    int p = 10;
    int a = sizeof(int) * p;
    printf("a=%d\n", a);
    return 0;
}