#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("pid=%d\n", getpid());
    printf("ppid=%d\n", getppid());
    printf("uid=%d\n", getuid());
    printf("euid=%d\n", geteuid());
    printf("gid=%d\n", getgid());
    printf("egid=%d\n", getegid());
    return 0;
}
/* pid=57663 */
/* ppid=57658 */
/* uid=1001 */
/* euid=1001 */
/* gid=1001 */
/* egid=1001 */
