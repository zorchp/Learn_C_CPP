
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void t1() {
    char* s1 = "123";
    char sa[10];
    char* ret = strcpy(sa, s1);
    printf("%s\n", s1);
    printf("%s\n", sa);
    printf("%s\n", ret);
}

void t2() {
    char sa[] = "123456";
    char ss[] = "123456789";
    strcpy(sa, ss);
    printf("%s\n", sa);
}

void t3() {
    char r[] = "1234";
    strcpy(r, "123456789");
    printf("%s\n", r);
}
int main(int argc, char* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}
