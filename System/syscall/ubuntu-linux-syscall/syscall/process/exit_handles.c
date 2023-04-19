#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void atexitFunc1(void) { printf("atexit func1 called\n"); }
static void atexitFunc2(void) { printf("atexit func2 called\n"); }

static void onexitFunc(int exitStatus, void *arg) {
    printf("on_exit func called: status=%d, arg=%ld\n", exitStatus, (long)arg);
}

int main(int argc, char *argv[]) {

    if (on_exit(onexitFunc, (void *)10)) fprintf(stderr, "on_exit 1\n");
    if (atexit(atexitFunc1)) fprintf(stderr, "atexit 1\n");
    if (atexit(atexitFunc2)) fprintf(stderr, "atexit 2\n");
    if (on_exit(onexitFunc, (void *)20)) fprintf(stderr, "on_exit 2\n");
    return 0;
}

/* on_exit func called: status=0, arg=20 */
/* atexit func2 called */
/* atexit func1 called */
/* on_exit func called: status=0, arg=10 */
