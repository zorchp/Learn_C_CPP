#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

static void /* Print 'msg' plus sysconf() value for 'name' */
sysconfPrint(const char *msg, int name) {
    long lim;

    errno = 0;
    lim = sysconf(name);
    if (lim != -1) { /* Call succeeded, limit determinate */
        printf("%s %ld\n", msg, lim);
    } else {
        if (errno == 0) /* Call succeeded, limit indeterminate */
            printf("%s (indeterminate)\n", msg);
        else /* Call failed */
            /* errExit("sysconf %s", msg); */
            fprintf(stderr, "error \n");
    }
}

extern char *program_invocation_name;
extern char *program_invocation_short_name;
int main(int argc, char *argv[]) {
    sysconfPrint("_SC_ARG_MAX:        ", _SC_ARG_MAX);
    sysconfPrint("_SC_LOGIN_NAME_MAX: ", _SC_LOGIN_NAME_MAX);
    sysconfPrint("_SC_OPEN_MAX:       ", _SC_OPEN_MAX);
    sysconfPrint("_SC_NGROUPS_MAX:    ", _SC_NGROUPS_MAX);
    sysconfPrint("_SC_PAGESIZE:       ", _SC_PAGESIZE);
    sysconfPrint("_SC_RTSIG_MAX:      ", _SC_RTSIG_MAX);
    printf("absolute path=%s\n", program_invocation_name);
    printf("relative path=%s\n", program_invocation_short_name);
    exit(EXIT_SUCCESS);
}
/* _SC_ARG_MAX:         2097152 */
/* _SC_LOGIN_NAME_MAX:  256 */
/* _SC_OPEN_MAX:        65535 */
/* _SC_NGROUPS_MAX:     65536 */
/* _SC_PAGESIZE:        4096 */
/* _SC_RTSIG_MAX:       32 */
/* absolute path=./sysconf-1.out */
/* relative path=sysconf-1.out */
