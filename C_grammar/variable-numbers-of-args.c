#include <stdarg.h> // you need to include this to use variable numbers of args
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计时
clock_t start_t, end_t;

// 打印函数的所有参数, 直到出现负数
void printArgs(int arg1, ...) {
    va_list ap;
    va_start(ap, arg1); // 捕获初始值
    // va_arg指定捕获参数的类型, 返回下一个参数
    // for (int i = arg1; i >= 0; i = va_arg(ap, int))
    //   printf("%d ", i);
    for (int i = arg1; i >= 0; i) printf("%d ", va_arg(ap, int));
    va_end(ap);    //释放参数列表内存
    putchar('\n'); //以换行符结尾
}

void calAverage(int arg1, ...) {
    va_list ap;
    register int i, total = 0, j = 0;

    va_start(ap, arg1);
    for (i = arg1; i; i = va_arg(ap, int)) {
        total += i;
        j++;
    }
    va_end(ap);
    printf("total(%d) is: %d, average is: %.2f\n", j, total,
           (double)total / (double)j);
}

void calAverage1(int num, ...) {
    va_list ap;
    register int i, total = 0;

    va_start(ap, num);
    for (i = 0; i < num; i++) { total += va_arg(ap, int); }
    va_end(ap);
    printf("total(%d) is: %d, average is: %.2f\n", num, total,
           (double)total / num);
}

int main() {
    start_t = clock();
    time_t t;
    srand((unsigned)time(&t));
    calAverage(5, 2, 14, 84, 97, 15, -1, -48, -1);
    printArgs(84, 51, -1, 3); // 84 51
    // for (int i = 0; i < 1000000; i+=10)
    //   calAverage1(3, rand() % 50, rand() % 50, rand() % 50);
    // end_t = clock();
    // printf("CLOCKS_PER_SEC is: %lu, total time is: %fms", CLOCKS_PER_SEC,
    //        (double)(end_t - start_t) / CLOCKS_PER_SEC * 1000);
    return 0;
}
