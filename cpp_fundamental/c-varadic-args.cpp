#include <climits> //INT_MAX
#include <cstdarg> // you need to include this to use variable numbers of args
#include <cstdio>
#include <cstdlib>
#include <ctime>

// 计时
clock_t start_t, end_t;


void printArgs(int arg1, ...) {
    /* 打印函数的所有参数, 直到出现负数 */
    va_list ap;
    va_start(ap, arg1); // 捕获初始值
    // va_arg指定捕获参数的类型, 返回下一个参数
    for (int i = arg1; i > 0; i = va_arg(ap, int)) printf("%d ", i);
    va_end(ap);    //释放参数列表内存
    putchar('\n'); //以换行符结尾
}

void findMax(int arg1, ...) {
    /*这个函数需要给定循环跳出的条件, 这里我设置为INT_MAX */
    va_list ap;
    int i, max1 = 0;

    va_start(ap, arg1);
    for (i = arg1; i != INT_MAX; i = va_arg(ap, int)) {
        max1 = max1 < i ? i : max1;
    }
    va_end(ap);
    printf("Max value is: %d\n\n", max1);
}

void calAverage(int arg1, ...) {
    /*这个函数需要给定循环跳出的条件, 这里我设置为INT_MAX */
    va_list ap;
    int i, total = 0, j = 0;

    va_start(ap, arg1);
    for (i = arg1; i != INT_MAX; i = va_arg(ap, int)) {
        total += i;
        j++;
    }
    va_end(ap);
    // printf("total(%d) is: %d, average is: %.2f\n", j, total,
    //     (double) total / j);
}

void calAverage1(int num, ...) {
    /*这里指定了读取参数的数量, 放在第一个参数位置*/
    va_list ap;
    int i, total = 0;

    va_start(ap, num);
    for (i = 0; i < num; i++) { total += va_arg(ap, int); }
    va_end(ap);
    // printf("total(%d) is: %d, average is: %.2f\n", num, total,
    //     (double) total / num);
}

void test1() {
    start_t = clock();
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < 100000000; i += 10)
        calAverage(rand() % 50, rand() % 50, rand() % 50, INT_MAX);
    end_t = clock();
    printf("test1, CLOCKS_PER_SEC is: %lu, total time is: %fms\n\n",
           CLOCKS_PER_SEC, (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000);
}

void test2() {
    start_t = clock();
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < 100000000; i += 10)
        calAverage1(3, rand() % 50, rand() % 50, rand() % 50);
    end_t = clock();
    printf("test2, CLOCKS_PER_SEC is: %lu, total time is: %fms\n\n",
           CLOCKS_PER_SEC, (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000);
}
int main() {
    // printf("%d", INT_MAX);
    printf("printArgs test:\n");
    printArgs(84, 51, -1, 3); // 84 51

    // -------------------------------- //
    printf("findMax test:\n");
    findMax(84, 51, -1, 3, INT_MAX); // 84
    // -------------------------------- //
    printf("calAverage test:\n");

    calAverage(2, 14, 84, 97, 15, -10, INT_MAX);
    calAverage1(6, 2, 14, 84, 97, 15, -10);
    // -------------------------------- //
    printf("calAverage time compare:\n");

    test1();
    test2();

    return 0;
}