/*******以下代码存放于file2.cpp中*******/
#include "file.h"

extern void sort(stu student[], int n) {
    int i, j, k;
    stu temp;

    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (student[j].score < student[k].score) k = j;
        }
        if (k != i) {
            temp       = student[i];
            student[i] = student[k];
            student[k] = temp;
        }
    }

    printf("使用选择法升序排列的结果为：\n");
    return;
}
