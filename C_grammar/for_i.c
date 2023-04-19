#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 100;

    for (int i = 0; i < 10; ++i) printf("%d ", i);
    printf("%d", i);
    return 0;
}
