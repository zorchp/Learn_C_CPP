#include <stdio.h>
#include <sys/time.h>


void dont_use_reg() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    /*测试起始时间*/
    double timeuse;
    double sum;
    int j, k;
    for (j = 0; j < 1000000000; j++)
        for (k = 0; k < 10; k++) sum = sum + 1.0;
    gettimeofday(&end, NULL);
    /*测试终止时间*/
    timeuse =
        1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    timeuse /= 1000000;
    printf("运行时间为：%f\n", timeuse);
    // 运行时间为：34.615811
}

void use_reg() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    /*测试起始时间*/
    double timeuse;
    register double sum;
    register int j, k;
    for (j = 0; j < 1000000000; j++)
        for (k = 0; k < 10; k++) sum = sum + 1.0;
    gettimeofday(&end, NULL);
    /*测试终止时间*/
    timeuse =
        1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    timeuse /= 1000000;
    printf("运行时间为：%f\n", timeuse);
    // 运行时间为：4.425275
}


int main(int argc, char* argv[]) {
    dont_use_reg();
    use_reg();

    /*
    用了register的程序执行速度提高了近3倍，但是读者要注意，虽然可以使用register来提高程序的执行速度，但是也不能大量使用register，因为寄存器的数目是有限的。
    */
    return 0;
}