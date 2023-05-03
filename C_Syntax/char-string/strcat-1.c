#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char s1[10] = {'s', '1'};
    printf("s1: %s\n", s1);
    char* s2 = "s2";
    printf("s2: %s\n", s2);
    char* s3 = strcat(s1, s2);
    printf("s3==s1: %d\n", (s3 == s1));
    printf("s1: %s, s2: %s, s3: %s\n", s1, s2, s3);
    char* s4 = strncat(s1, s2, 3);
    printf("s4==s3: %d, s3==s1: %d\n", (s4 == s3), (s3 == s1));
    printf("s1: %s, s2: %s, s3: %s, s4: %s\n", s1, s2, s3, s4);
    return 0;
}
