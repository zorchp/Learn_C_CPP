#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr[], size_t SIZE) {
    // size_t N = sizeof(arr) / sizeof(int*);//1
    // printf("%lu, %lu\n", sizeof(arr), sizeof(int*));//8,8
    for (int i = 0; i < SIZE; i++) { printf("%d ", *arr[i]); }
    printf("\n");
}

void t1() {
    int* arr[5]; //存放的是int*类型
    size_t SIZE = sizeof(arr) / sizeof(int*);
    // printf("%lu, %lu\n", sizeof(arr), sizeof(int*));//40,8
    for (int i = 0; i < 5; i++) {
        //分配空间
        arr[i]  = (int*)malloc(sizeof(int));
        *arr[i] = i;
        // printf("%d\n", *arr[i]);
    }
    printf("arr:\n");
    printArr(arr, SIZE);

    printf("*arr[0]:%d\n", *arr[0]);       // 0
    printf("**arr:%d\n", **arr);           // 0
    printf("**(arr+1):%d\n", **(arr + 1)); // 1
    printf("arr[0][0]:%d\n", arr[0][0]);   // 0
    printf("arr[3][0]:%d\n", arr[3][0]);   // 3
    /*
    arr:
    0 1 2 3 4
    *arr[0]:0
    **arr:0
    **(arr+1):1
    arr[0][0]:0
    arr[3][0]:3
    */
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}