#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    int filedes[2];
    if (pipe(filedes) == -1) fprintf(stderr, "pipe\n");
    switch (fork()) {
        case -1:
            fprintf(stderr, "fork\n");
        case 0: // child process
            if (close(filedes[1]) == -1) fprintf(stderr, "close\n");
            break;
        default: // parent
            if (close(filedes[0]) == -1) fprintf(stderr, "close \n");
            break;
    }
    return 0;
}
