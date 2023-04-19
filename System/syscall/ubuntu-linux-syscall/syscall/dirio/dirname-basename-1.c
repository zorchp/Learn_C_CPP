#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* path = "/home/zorch/Desktop/firefox.desktop";
    char *t1, *t2;
    t1 = strdup(path);
    t2 = strdup(path);
    printf("dirname is %s\n", dirname(t1));
    printf("basename is %s\n", basename(t2));
    free(t1);
    free(t2);
    return 0;
}
/* dirname is /home/zorch/Desktop */
/* basename is firefox.desktop */
