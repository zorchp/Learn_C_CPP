#include <stdio.h>

void t1() {
    char cc[5] = "abc";
    cc[1]      = NULL;
    printf("%s\n", cc);
    printf("NULL==0: %d", NULL == 0); // 1
    /*
    warning: assignment to 'char' from 'void *' makes integer from pointer
    without a cast [-Wint-conversion] 5 |     cc[1] = NULL;*/
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}