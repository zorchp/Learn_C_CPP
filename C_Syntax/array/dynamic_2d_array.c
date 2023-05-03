#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    int **arr, i, j;
    // printf("请输入所要创建的动态数组的第一维长度：");
    // scanf("%d", &n1);
    // printf("请输入所要创建的动态数组的第二维长度：");
    // scanf("%d", &n2);
    // n1 = n2 = 3000000000L;//error
    n1 = n2 = 3;

    if ((arr = (int **)malloc(n1 * sizeof(int *))) == NULL) //第一维的创建
    {
        printf("分配内存空间失败!\n");
        return 0;
    }

    for (i = 0; i < n1; i++) {
        if ((arr[i] = (int *)malloc(n2 * sizeof(int))) == NULL) //第二维的创建
        {
            printf("分配内存空间失败!\n");
            return 0;
        }
    }
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            arr[i][j] = i * n2 + j + 1;
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i<n1; i++) {
        free(arr[i]); //释放第二维
    }
    free(arr); //释放第一维

    return 0;
}