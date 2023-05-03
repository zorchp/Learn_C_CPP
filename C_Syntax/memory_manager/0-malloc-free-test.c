#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void t1() {
    int *pi1 = (int *)malloc(sizeof(int));
    //加上(int*)目的是强转malloc默认的返回值(void*)为对应的数据类型的指针,
    //可以不加, 通过隐式类型转换完成
    /* refer to 深入理解C指针
    C引入void指针之前，在两种互不兼容的指针类型之间赋值,
    需要对malloc使用显式转换类型以避免产生警告。
    因为可以将void指针赋值给其他任何指针类型，所以就不再需要显式类型转换了。
    有些开发者认为显式类型转换是不错的做法，因为：
    · 这样可以说明malloc函数的用意；
    · 代码可以和C++（或早期的C编译器）兼容，后两者需要显式的类型转换。
    */
    int *pi = (int *)malloc(2 * sizeof(int));
    *pi     = 5;
    printf("*pi: %d,pi: %p\n", *pi, pi);
    printf("sizeof(*pi): %lu\n", sizeof(*pi));
    free(pi);
    // pi = NULL;//将指针置为0, 否则仍然指向刚才的内存, 成为迷途指针
    printf("pi: %p,*pi: %d\n", pi, *pi);
    /*
    *pi: 5,pi: 0x600002cf4040
    sizeof(*pi): 4
    pi: 0x0
    */
}

void t2() {
    char *pc = (char *)malloc(6); //可以存放5字符
    for (int i = 0; i < 8; i++) {
        pc[i] = '\0'; // equal to 0
    }
    printf("pc=%p, *pc=%c, sizeof(pc)=%lu\n", pc, *pc, sizeof(pc));
}

void t3() {
    // memory leak
    char *chunk;
    while (1) {
        chunk = (char *)malloc(1000000);
        printf("Allocating\n");
    }
}

void t4() {
    int *pi = (int *)malloc(sizeof(int));
    *pi     = 5;
    printf("*pi=%d\n", *pi); // 5
    pi = (int *)malloc(sizeof(int));
    printf("*pi=%d\n", *pi); // 0
}

void t5() {
    char *name = (char *)malloc(strlen("Susan") + 1); //+1表示 \0占用的内存
    char *cur = name;
    strcpy(name, "Susan");
    while (*cur != 0) {
        printf("%c\n", *cur);
        printf("%p\n", cur);
        cur++; //如果直接用name++;
               //初始分配的内存地址丢失了,这里通过一个新的指针变量cur完成
    }
    printf("%p\n", name);
}
int main(int argc, char const *argv[]) {
    t1();
    // t2();
    // t3();
    // t4();
    // t5();
    return 0;
}