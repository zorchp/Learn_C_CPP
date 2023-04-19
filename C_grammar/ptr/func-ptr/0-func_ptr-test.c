#include <stdio.h>
#include <stdlib.h>


void test(char* ss) { printf("nihao,%s\n", ss); }


int max(int x, int y) { return x > y ? x : y; }


void test1() {
    /* p 是函数指针 */
    int (*p)(int, int) = &max; // &可以省略
    printf("max=%p\n", max);
    printf("&max=%p\n", &max); //函数名和函数名前面加取地址符号, 都为一样的地址
    printf("sizeof(max)=%lu\n", sizeof(max));
    void (*ps)(char*) = &test;
    int a = 1, b = 2, c = 4, d;
    ps("cecece");

    // printf("请输入三个数字:");
    // scanf("%d %d %d", & a, & b, & c);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c);

    printf("最大的数字是: %d\n", d);
}

// ---------------------------------- //
// 回调函数
void populate_array(int array[], size_t arraySize, int (*getNextValue)(void)) {
    for (size_t i = 0; i < arraySize; i++) array[i] = getNextValue();
}


// 获取随机值
int getNextRandomValue(void) { return rand() % 100; }


void test2() {
    int myarray[10];
    /* getNextRandomValue
     * 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int ,
     * 而不是函数指针*/
    int (*fun)(void) = &getNextRandomValue;
    populate_array(myarray, 10, fun);
    // 遍历数组
    for (int i = 0; i < 10; i++) { printf("%d ", myarray[i]); }
    printf("\n");
}


void test_rand() {
    srand((unsigned int)10);
    printf("%d\n", rand() % 100);
}


int main(void) {
    // test_rand();
    test1();
    // test2();

    return 0;
}