#include <cstdio>

int main(int argc, char const *argv[]) {
    int i = 1;
    char *p = (char *)&i;
    if (*p == 1)
        printf("Little Endian"); //!
    else
        printf("Big Endian");
    return 0;
}