#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int numChild, j;
    pid_t childPid;

    numChild = 100;
    setbuf(stdout, NULL); // 关闭缓存
    for (j = 0; j < numChild; ++j) {
        switch (childPid = fork()) {
            case -1:
                fprintf(stderr, "fork\n");
            case 0: // child
                printf("%d child\n", j);
                _exit(EXIT_SUCCESS);
            default: // parent
                printf("%d parent\n", j);
                wait(NULL);
                break;
        }
    }
    return 0;
}
