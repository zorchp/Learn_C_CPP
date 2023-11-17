#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //for non_blocking read

void t1() {
    char buf[100];
    int ans = read(0, buf, 5);
    printf("%s\n", buf);
    printf("%d\n", ans);
}

void t2() {
    char buf[100];
    int flg = fcntl(0, F_GETFL);
    flg |= O_NONBLOCK;
    int set_ans = fcntl(0, F_SETFL, flg);
    printf("%d\n", set_ans);

    int ans = read(0, buf, 5);
    puts("start:\n");
    printf("%s\n", buf);
    printf("%d\n", ans);
}

int main(int argc, char *argv[]) {
    // t1();
    t2();

    return EXIT_SUCCESS;
}
