#include <stdio.h>

int main(int argc, char const *argv[]) {
    double n = 1, p = n / 0;
    printf("%f\n", p);
    return 0;
}