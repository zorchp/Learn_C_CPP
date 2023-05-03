#include <stdio.h>

int main(int argc, char const* argv[]) {
    char* a = "dka";
    printf("%p, %c\n", a, *(a + 1));
    return 0;
}