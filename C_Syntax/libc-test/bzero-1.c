#include <string.h>
#include <stdio.h>

int main(int argc, char const* argv[]) {
    char s1[] = "abc";
    char* s2 = "abc";
    printf("%s\n", s1);
    // printf("%d\n", strlen(s1));
    // printf("%d\n", strlen(s2));
    // s2[0] = 'e';
    bzero(s1, 0);
    printf("%s\n", s1);
    bzero(s1, 1);
    printf("%s\n", s1);

    return 0;
}