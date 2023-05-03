#include <stdio.h>

#define N 10

int* modifyArr(int arr[], int idx, int val) {
    arr[idx] = val;
    return arr;
}


void printArr(int arr[]) {
    for (int i = 0; i < N; i++) { printf("%d ", arr[i]); }
    printf("\n");
}


int main(int argc, char const* argv[]) {
    int arr[N] = {1, 2, 3, 3, 3, 13, 234, 2332, 12};
    printArr(arr);
    modifyArr(arr, 1, 100389);
    printArr(arr);
    return 0;
}