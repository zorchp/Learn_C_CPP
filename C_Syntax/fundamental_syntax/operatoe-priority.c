#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n = 10;
    if (n & 1) printf("n is odd\n");
    if (n & 1 == 0) printf("n is even\n");
    return 0;
}