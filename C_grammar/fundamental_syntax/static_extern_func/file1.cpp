/*******以下代码存放于file1.cpp中*******/
#include "file.h"
static void input(stu student[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("请输入学生的姓名：");
        scanf("%s", student[i].name);
        printf("请输入学生的总成绩：");
        scanf("%d", &student[i].score);
    }

    return;
}

int main(void) {
    stu student[4];
    extern void sort(stu student[], int n);
    extern void bubble_sort(stu student[], int n);
    extern void print(stu student[], int n);
    input(student, 4);

    sort(student, 4);
    print(student, 4);

    bubble_sort(student, 4);
    print(student, 4);

    return 0;
}
