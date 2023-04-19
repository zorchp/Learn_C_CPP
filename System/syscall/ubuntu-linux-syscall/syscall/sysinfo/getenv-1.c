#include <stdio.h>
#include <stdlib.h>

void t1() {
    printf("LANG=%s\n", getenv("LANG"));
    printf("PWD=%s\n", getenv("PWD"));
    printf("SHELL=%s\n", getenv("SHELL"));
}

extern char** environ;
void t2() {
    int i = 0;
    while (environ[i] != NULL) printf("environ[%d]=%s\n", i, environ[i]), ++i;
}
/* environ[0]=SHELL=/bin/bash */

int main(int argc, char* argv[], char* envp[]) {
    /* t1(); */
    /* t2(); */
    for (int i = 0; envp[i] != NULL; ++i) printf("envp[%d]=%s\n", i, envp[i]);
    return 0;
}
