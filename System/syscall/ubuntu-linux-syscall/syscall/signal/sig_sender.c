#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
const int PID = 742737;
const int NUM_SIG = 1000000;
const int SIG = 10;
const int SIG_2 = 2;

int main(int argc, char *argv[]) {
    int numSigs, sig, j;
    pid_t pid;
    pid = PID;
    numSigs = NUM_SIG;
    sig = SIG;

    printf("%s sending signal %d to process %ld %d times \n", argv[0], sig,
           (long)pid, numSigs);

    for (j = 0; j < numSigs; ++j)
        if (kill(pid, sig) == -1) fprintf(stderr, "kill error\n");
    if (SIG_2)
        if (kill(pid, SIG_2) == -1) fprintf(stderr, "kill error\n");

    printf("%s: exiting\n", argv[0]);
    return 0;
}
