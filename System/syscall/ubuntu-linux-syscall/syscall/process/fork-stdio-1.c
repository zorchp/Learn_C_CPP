#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    printf("h w\n");
    write(STDOUT_FILENO, "cio\n", 5);
    /* fflush(stdout); */
    setbuf(stdout, NULL);
    if (fork() == -1) fprintf(stderr, "fork error\n");
    exit(EXIT_SUCCESS);
}
