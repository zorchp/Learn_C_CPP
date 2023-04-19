#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a = 0;

pthread_mutex_t lock;

void* myfunc(void* args) {
    // printf("hello\n");
    char* s = args;
    pthread_mutex_lock(&lock);

    for (int i = 0; i < 5000000; ++i) {
        // printf("%s: %d\n", s, i);
        // pthread_mutex_lock(&lock);
        a++;
        // pthread_mutex_unlock(&lock);
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char const* argv[]) {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, myfunc, "t1");
    pthread_create(&t2, NULL, myfunc, "t2");
    pthread_join(t1, NULL); //等待子线程完成
    pthread_join(t2, NULL); //等待子线程完成
    printf("a=%d\n", a);
    return 0;
}