#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// init mutex lock
pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER,
                mtx2 = PTHREAD_MUTEX_INITIALIZER;

static void* func1(void* arg) {
    pthread_mutex_lock(&mtx1);
    char* s = (char*)arg;
    printf("%s", s);
    pthread_mutex_lock(&mtx2);
    return (void*)strlen(s);
}
static void* func2(void* arg) {
    pthread_mutex_lock(&mtx2);
    char* s = (char*)arg;
    printf("%s", s);
    pthread_mutex_lock(&mtx1);

    return (void*)strlen(s);
}

int main(int argc, char* argv[]) {
    pthread_t t1, t2;
    void* res;
    int s;
    s = pthread_create(&t1, NULL, func1, "hello pthread1\n");
    if (s) fprintf(stderr, "pthread_create");

    s = pthread_create(&t2, NULL, func2, "hello pthread2\n");
    if (s) fprintf(stderr, "pthread_create");

    printf("msg from main():\n");

    s = pthread_join(t1, &res);
    if (s) fprintf(stderr, "pthread_join");

    s = pthread_join(t2, &res);
    if (s) fprintf(stderr, "pthread_join");

    printf("thread returned: %ld\n", (long)res);

    return 0;
}
