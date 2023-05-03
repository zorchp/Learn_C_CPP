#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
    char s1[]= "aae";
    char s2[] = "cde";
    printf("s1:%p, s2:%p, s1>s2:%d\n", s1, s2, s1 > s2);
    char *s3 = "aae";
    char *s4 = "cde";
    printf("s3:%p, s4:%p, s3>s4:%d\n", s3, s4, s3 > s4);
    // char* p = "hello";
    // p++;
    // printf("%s\n", p);
    return 0;
}
