#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prints(char* s) {
    for (int i = 0; i < strlen(s); i++) printf("%c", s[i]);
    putchar('\n');
}

void t1() {
    //字符串字面量
    char* s1 = "abcde\0";
    printf("%d\n", strlen(s1)); // 5
}

void t2() {
    char s2[10];
    strcpy(s2, "abcde");
    printf("%d\n", strlen(s2)); // 5
}

void t3() {
    char* s3 = (char*)malloc(strlen("hello") + 1);
    strcpy(s3, "hello");
    prints(s3);
}
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}