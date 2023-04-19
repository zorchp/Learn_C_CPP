#include <stdio.h>
int main(int argc, char const *argv[]) {
    int num = 8;
    int *pi = (int *)num;
    printf("%d\n", *pi); // fault
    return 0;
}