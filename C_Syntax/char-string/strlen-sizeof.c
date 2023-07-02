#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void t1() {
    const char* s = "1,2,3\0jd";
    printf("%ld\n", sizeof(s)); // 8
    printf("%ld\n", strlen(s)); // 5
}

int main(int argc, char* argv[]) {
    t1();

    return EXIT_SUCCESS;
}
