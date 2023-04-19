#include <stdio.h>
#include <stdlib.h>


void t1() {
    int *pi = (int *)malloc(1e16L * sizeof(int));
    if (pi != NULL) {
        // 指针没有问题
        printf("%s\n", "指针没问题!");
    } else {
        // 无效的指针
        printf("%s\n", "无效的指针!");
        printf("pi=%p\n.", pi); //此时pi=NULL,or 0x0
    }
    free(pi);
}

void t2() {
    int *pi;
    printf("pi=%p, *pi=%d\n", pi, *pi); //未分配内存, 此时给出默认值0
}

void t3() {
    const int NUMBER_OF_DOUBLES = 10;
    double *pd = (double *)malloc(NUMBER_OF_DOUBLES * sizeof(double)); // 80

    double *pd1 = (double *)malloc(NUMBER_OF_DOUBLES); // 10
}

void t4() {
    /*
    静态、全局指针和malloc:
    初始化静态或全局变量时不能调用函数。下面的代码声明一个静态变量，并试图用malloc来初始化
    */
    // error: initializer element is not a compile-time constant
    //  static int *pi = malloc(sizeof(int));
    //  可以通过两行的方式解决, 但是全局变量一定不能用malloc, 主要是因为:
    //  在编译器看来，作为初始化操作符的=和作为赋值操作符的=不一样。
    static int *pi;
    pi = malloc(sizeof(int));
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}