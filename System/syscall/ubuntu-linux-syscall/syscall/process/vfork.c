#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int istack = 222;
    switch (vfork()) {
        case -1:
            fprintf(stderr, "vfork");
            exit(1);
        case 0: // child
            sleep(3);
            write(STDOUT_FILENO, "child executing\n", 16);
            istack *= 3;
            _exit(EXIT_SUCCESS);
        default:
            write(STDOUT_FILENO, "Parent executing\n", 17);
            printf("istack=%d\n", istack);
            exit(EXIT_SUCCESS);
    }
    return 0;
}
/* child executing */
/* Parent executing */
/* istack=666 */
