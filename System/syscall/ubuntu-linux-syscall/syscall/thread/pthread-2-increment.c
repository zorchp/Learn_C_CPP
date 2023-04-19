#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int glob = 0;
// init mutex lock
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* func(void* arg) {
    int loops = *((int*)arg);
    int loc, j, s;
    /* s = pthread_mutex_lock(&mtx); */
    /* if (s) fprintf(stderr, "pthread_mutex_lock"); */
    for (j = 0; j < loops; ++j) {
        s = pthread_mutex_lock(&mtx);
        if (s) fprintf(stderr, "pthread_mutex_lock");
        loc = glob;
        ++loc;
        glob = loc;
        s = pthread_mutex_unlock(&mtx);
        if (s) fprintf(stderr, "pthread_mutex_unlock");
    }
    /* s = pthread_mutex_unlock(&mtx); */
    /* if (s) fprintf(stderr, "pthread_mutex_unlock"); */
    return NULL;
}


int main(int argc, char* argv[]) {
    pthread_t t1, t2;
    int loops, s;
    loops = 10000000;
    s = pthread_create(&t1, NULL, func, &loops);
    if (s) fprintf(stderr, "pthread_create");
    s = pthread_create(&t2, NULL, func, &loops);
    if (s) fprintf(stderr, "pthread_create");
    s = pthread_join(t1, NULL);
    if (s) fprintf(stderr, "pthread_join");
    s = pthread_join(t2, NULL);
    if (s) fprintf(stderr, "pthread_join");

    printf("glob = %d\n", glob);
    // after locked:
    /* glob = 20000000 */

    return 0;
}
// Lock outside the for loop
/* glob = 200000000 */
/*  */
/* real    0m0.896s */
/* user    0m0.889s */
/* sys     0m0.000s */

// inside:
/* glob = 200000000 */
/*  */
/* real    0m18.602s */
/* user    0m22.255s */
/* sys     0m13.218s */
