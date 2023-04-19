
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* s1 = "123";
    char sa[10];
    char* ret = strcpy(sa, s1);
    printf("%s\n", s1);
    printf("%s\n", sa);
    printf("%s\n", ret);
    return 0;
}
