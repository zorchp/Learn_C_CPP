#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    // printf("请输入所要创建的一维动态数组的长度:");
    // scanf("%d", &n);
    // n = 1000000000000L;//error
    n = 10;
    if ((arr = (int *)malloc(sizeof(int) * n)) == NULL) {
        printf("分配内存空间失败!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
        printf("%d\t", arr[i]);
        if (0 == (i + 1) % 4) printf("\n");
    }
    free(arr);

    return 0;
}