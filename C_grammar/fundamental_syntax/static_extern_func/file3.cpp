/*******以下代码存放于file3.cpp中*******/
#include "file.h"

void bubble_sort(stu student[], int n) {
    int i, j, flag;
    stu temp;

    for (i = 0; i < n - 1; i++) {
        flag = 1;

        for (j = 0; j < n - i - 1; j++) {
            if (student[j].score < student[j + 1].score) {
                temp           = student[j];
                student[j]     = student[j + 1];
                student[j + 1] = temp;
                flag           = 0;
            }
        }
        if (1 == flag) break;
    }

    printf("使用冒泡法降序排列的结果为：\n");

    return;
}
