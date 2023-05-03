#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void t1() {
    // calloc的用处是清空内存并初始化为0, 下面是函数声明
    // void *calloc(size_t numElements, size_t elementSize);
    //清空内存的意思是将其内容置为二进制0
    /*calloc函数会根据numElements和elementSize两个参数的乘积来分配内存，并返回一个指向内存的第一个字节的指针。如果不能分配内存，则会返回NULL。此函数最初用来辅助分配数组内存。如果numElements或elementSize为0，那么calloc可能返回空指针。如果calloc无法分配内存就会返回空指针，而且全局变量errno会设置为ENOMEM（内存不足），这是POSIX错误码，有的系统上可能没有。*/
    int *pi = calloc(5, sizeof(int));
    printf("%p,%p\n", pi, (pi + 1));
    printf("%d,%d\n", *pi, *(pi + 1));

    // equal to (use malloc and memset)
    int *pi1 = malloc(5 * sizeof(int));
    memset(pi1, 0, 5 * sizeof(int));
    printf("%p,%p\n", pi1, (pi1 + 1));
    printf("%d,%d\n", *pi1, *(pi1 + 1));
}

void t2() {
    // realloc
    char *string1;
    char *string2;
    string1 = (char *)malloc(16);
    strcpy(string1, "0123456789AB");
    string2 = realloc(
        string1,
        8); //此时虽然仍打印出所有的字符串内容, 但是却占用了未分配的内存空间
    //通过给指针string2+7赋值的方式使其满足内存分配的大小
    *(string2 + 7) = 0;
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);
    /*
    string1 Value: 0x600002ab4030 [0123456789AB]
    string2 Value: 0x600002ab4030 [0123456789AB]
    //添加+7赋值之后:
    string1 Value: 0x600000e70030 [0123456]
    string2 Value: 0x600000e70030 [0123456]
    */
}

void t3() {
    char *string1;
    char *string2;
    string1 = (char *)malloc(16);
    strcpy(string1, "0123456789AB");
    string2 = realloc(string1, 64); //分配更大的内存
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);
    /*
    string1 Value: 0x600000288030 [0�O�]
    string2 Value: 0x60000158c1c0 [0123456789AB]
    */
}


int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}