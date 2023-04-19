#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    struct utsname uts;
    if (uname(&uts) == -1) fprintf(stderr, "uname"), exit(1);
    printf("__linux__=%d\n", __linux__); // 1

    printf("Node name:   %s\n", uts.nodename);
    printf("System name: %s\n", uts.sysname);
    printf("Release:     %s\n", uts.release);
    printf("Version:     %s\n", uts.version);
    printf("Machine:     %s\n", uts.machine);
#ifdef _GNU_SOURCE
    printf("Domain name: %s\n", uts.domainname);
#endif
    exit(EXIT_SUCCESS);
    return 0;
}
/* Node name:   xxx */
/* System name: Linux */
/* Release:     5.4.0-135-generic */
/* Version:     #152-Ubuntu SMP Wed Nov 23 20:19:22 UTC 2022 */
/* Machine:     x86_64 */
