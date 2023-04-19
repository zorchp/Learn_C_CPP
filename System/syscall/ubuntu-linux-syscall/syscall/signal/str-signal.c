#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#define getsig(x) (#x)

extern const char* const sys_siglist[];
void t1() {
    int sig = SIGPIPE;
    printf("sig:%d, %s, info:%s\n", sig, getsig(SIGPIPE), sys_siglist[sig]);
    /* sig:13, SIGPIPE, info:Broken pipe */
}

extern char* strsignal(int);
void t2() {
    printf("sig:%d, %s, info:%s\n", SIGPIPE, getsig(SIGPIPE),
           strsignal(SIGPIPE));
    /* sig:13, SIGPIPE, info:Broken pipe */
}

int main(int argc, char* argv[]) {
    /* t1(); */
    t2();
    return 0;
}
