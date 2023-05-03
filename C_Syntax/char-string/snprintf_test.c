#include <stdio.h>
// #include <stdlib.h>

void test1() {
    // printf("%s\n", "你好世界");
    char buf[10];
    char* s = "9834993";

    // int j = snprintf(buf, 6, "%d", 9834993);
    // int j = snprintf(buf, 6, "%s", s);
    int j = snprintf(buf, 6, "%ld", 30000000L);

    printf("buf:%s, j: %d\n", buf, j);
}

int main(int argc, char const* argv[]) {
    test1();
    return 0;
}