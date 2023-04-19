#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void* func(void* arg) {
    char* s = (char*)arg;
    printf("%s", s);
    return (void*)strlen(s);
}


int main(int argc, char* argv[]) {
    pthread_t t1;
    void* res;
    int s;
    s = pthread_create(&t1, NULL, func, "hello pthread\n");

    if (s) fprintf(stderr, "pthread_create");
    printf("msg from main():\n");
    s = pthread_join(t1, &res);
    if (s) fprintf(stderr, "pthread_join");

    printf("thread returned: %ld\n", (long)res);
    /* msg from main(): */
    /* hello pthread */
    /* thread returned: 14 */


    return 0;
}
