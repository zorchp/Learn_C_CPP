#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 10

int main(int argc, char* argv[]) {
    int pfd[2]; /* Pipe file descriptors */
    char buf[BUF_SIZE];
    ssize_t numRead;


    if (pipe(pfd) == -1) /* Create the pipe */
        fprintf(stderr, "pipe");

    switch (fork()) {
        case -1:
            fprintf(stderr, "fork");

        case 0:                      /* Child  - reads from pipe */
            if (close(pfd[1]) == -1) /* Write end is unused */
                fprintf(stderr, "close - child");

            for (;;) { /* Read data from pipe, echo on stdout */
                numRead = read(pfd[0], buf, BUF_SIZE);
                if (numRead == -1) fprintf(stderr, "read");
                if (numRead == 0) break; /* End-of-file */
                if (write(STDOUT_FILENO, buf, numRead) != numRead)
                    fprintf(stderr, "child - partial/failed write");
            }

            write(STDOUT_FILENO, "\n", 1);
            if (close(pfd[0]) == -1) fprintf(stderr, "close");
            exit(EXIT_SUCCESS);

        default:                     /* Parent - writes to pipe */
            if (close(pfd[0]) == -1) /* Read end is unused */
                fprintf(stderr, "close - parent");

            const char* str = "test output";
            size_t size = strlen(str);
            if (write(pfd[1], str, size) != size)
                fprintf(stderr, "parent - partial/failed write");

            if (close(pfd[1]) == -1) /* Child will see EOF */
                fprintf(stderr, "close");
            wait(NULL); /* Wait for child to finish */
            exit(EXIT_SUCCESS);
    }

    // test output
}
