#include <stdio.h>
#include <stdlib.h>

void t1() {
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof arr=%d\n", n);
    // sizeof arr=10
}
void t2(int arr[]) {
    // treat arr as a pointer
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof arr=%d\n", n); // sizeof arr=2
}
void t3(int *arr) {
    // treat arr as a pointer
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("sizeof arr=%d\n", n); // sizeof arr=2
}
int main(int argc, char *argv[]) {
    int arr[12] = {1, 2, 3, 4, 5};
    t1();
    t2(arr);
    t3(arr);
    return 0;
}
