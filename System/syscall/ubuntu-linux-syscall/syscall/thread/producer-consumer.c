#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static int avail = 0;

static void *producer(void *arg) {
    int cnt = atoi((char *)arg);

    for (int j = 0; j < cnt; j++) {
        sleep(1);

        /* Code to produce a unit omitted */
        int s = pthread_mutex_lock(&mtx);
        if (s != 0) fprintf(stderr, "pthread_mutex_lock");

        avail++; /* Let consumer know another unit is available */

        s = pthread_mutex_unlock(&mtx);
        if (s != 0) fprintf(stderr, "pthread_mutex_unlock");
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    time_t t = time(NULL);

    int totRequired = 0; /* Total number of units that all
                            threads will produce */
    /* Create all threads */

    for (int j = 1; j < argc; j++) {
        totRequired += atoi(argv[j]);

        pthread_t tid;
        int s = pthread_create(&tid, NULL, producer, argv[j]);
        if (s != 0) fprintf(stderr, "pthread_create");
    }

    /* Use a polling loop to check for available units */

    int numConsumed = 0; /* Total units so far consumed */
    bool done = false;

    for (;;) {
        int s = pthread_mutex_lock(&mtx);
        if (s != 0) fprintf(stderr, "pthread_mutex_lock");

        while (avail > 0) { /* Consume all available units */

            /* Do something with produced unit */

            numConsumed++;
            avail--;
            printf("T=%ld: numConsumed=%d\n", (long)(time(NULL) - t),
                   numConsumed);

            done = numConsumed >= totRequired;
        }

        s = pthread_mutex_unlock(&mtx);
        if (s != 0) fprintf(stderr, "pthread_mutex_unlock");

        if (done) break;

        /* Perhaps do other work here that does not require mutex lock */
    }

    exit(EXIT_SUCCESS);
}
