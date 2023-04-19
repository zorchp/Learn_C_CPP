#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid == 0)
        puts("child process");
    else {
        printf("child process's pid is %d \n", pid);
        sleep(30);
    }

    if (pid == 0)
        puts("end child process");
    else
        puts("end parent process");
    return 0;
}
/*  ==> ps aux|grep Z+ */
/* hep              88171   0.0  0.0 408628368   1648 s002  S+   10:33下午
 * 0:00.00 grep Z+ */
/* hep              88055   0.0  0.0        0      0 s000  Z+   10:33下午
 * 0:00.00 (zombie.out) */

// by using `./xxx &`, background run:
/*  ==> ps aux|grep zom */
/* hep              88414   0.0  0.0 408628368   1648 s002  S+   10:35下午
 * 0:00.00 grep zom */
/* hep              88289   0.0  0.0        0      0 s000  ZN   10:35下午
 * 0:00.00 (zombie.out) */
/* hep              88287   0.0  0.0 408497232   1424 s000  SN   10:35下午
 * 0:00.00 ./zombie.out */
