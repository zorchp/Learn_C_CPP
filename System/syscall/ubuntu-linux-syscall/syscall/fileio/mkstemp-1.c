#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char tmp[] = "/tmp/test-XXXXXX";
    // must use char xx[], not char*
    // must use XXXXXX not xxxxxx
    int fd = mkstemp(tmp);
    if (fd == -1) fprintf(stderr, "mkstemp");
    sleep(2);
    printf("temp file name is %s\n", tmp);
    printf("temp file fd is %d\n", fd);
    sleep(2);
    unlink(tmp);

    if (close(fd) == -1) fprintf(stderr, "close");
    /* temp file name is /tmp/test-Y4PE69 */
    /* temp file fd is 3 */
    return 0;
}
