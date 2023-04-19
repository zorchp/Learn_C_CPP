#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

static void /* Print 'msg' plus value of fpathconf(fd, name) */
fpathconfPrint(const char *msg, int fd, int name) {
    long lim;

    errno = 0;
    lim = fpathconf(fd, name);
    if (lim != -1) { /* Call succeeded, limit determinate */
        printf("%s %ld\n", msg, lim);
    } else {
        if (errno == 0) /* Call succeeded, limit indeterminate */
            printf("%s (indeterminate)\n", msg);
        else /* Call failed */
            /* errExit("fpathconf %s", msg); */
            fprintf(stderr, "error");
    }
}

int main(int argc, char *argv[]) {
    fpathconfPrint("_PC_NAME_MAX: ", STDIN_FILENO, _PC_NAME_MAX);
    fpathconfPrint("_PC_PATH_MAX: ", STDIN_FILENO, _PC_PATH_MAX);
    fpathconfPrint("_PC_PIPE_BUF: ", STDIN_FILENO, _PC_PIPE_BUF);
    exit(EXIT_SUCCESS);
}
/* _PC_NAME_MAX:  255 */
/* _PC_PATH_MAX:  4096 */
/* _PC_PIPE_BUF:  4096 */
