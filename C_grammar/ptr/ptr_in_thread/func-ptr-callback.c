#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// declare here
void *factorial(void *);
typedef struct _factorialData FactorialData;
void startThread(FactorialData *);
void callBackFunction(FactorialData *);
// declare end

struct _factorialData {
    int number;
    int result;
    void (*callBack)(struct _factorialData *);
};

int main(int argc, char const *argv[]) {
    FactorialData *data = (FactorialData *)malloc(sizeof(FactorialData));
    if (!data) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    data->number   = 5;
    data->callBack = callBackFunction;
    startThread(data);
    sleep(2); // 2s
    return 0;
}

void *factorial(void *args) {
    FactorialData *factorialData = (FactorialData *)args;
    void (*callBack)(FactorialData *); // 函数原型
    int number = factorialData->number;
    callBack   = factorialData->callBack;
    int num    = 1;
    for (int i = 1; i <= number; i++) { num *= i; }
    factorialData->result = num;
    callBack(factorialData);
    pthread_exit(NULL);
}

void startThread(FactorialData *data) {
    pthread_t thread_id;
    int thread = pthread_create(&thread_id, NULL, factorial, (void *)data);
}

void callBackFunction(FactorialData *factorialData) {
    printf("Factorial is %d\n", factorialData->result);
}