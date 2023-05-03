#include <stdio.h>
#include <stdlib.h>


float average(int *arr, int size) {
    int sum = 0; // stack frame
    printf("arr=%d, &arr: %p\n", *arr, &arr);
    printf("sie=%d, &size: %p\n", size, &size);
    printf("sum=%d, &sum: %p\n", sum, &sum);
    for (int i = 0; i < size; i++) { sum += arr[i]; }
    return (sum * 1.0f) / size;
}
void t1() {
    int *arr1 = (int *)malloc(sizeof(int) * 3);
    // int arr1[3];
    arr1[0] = 1;
    arr1[1] = 4;
    arr1[2] = 3;

    float ans = average(arr1, 3);
    printf("%f\n", ans);
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}