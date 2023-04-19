#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>   // time()


int main(int argc, char const *argv[]) {
    printf("RAND_MAX: %d\n", RAND_MAX);
    // set time to random seed
    time_t tm = time(NULL);
    srand(tm);
    printf("rand:(from 0~%d, seed: %ld) is: %d\n", RAND_MAX, tm, rand());
    return 0;
}