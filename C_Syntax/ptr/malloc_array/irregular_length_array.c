#include <stdio.h>
#include <stdlib.h>
/*采用C的复合字面量创建不规则长度数组 */

void t0() {
    /*复合字面量*/
    const int a = (const int){100};     //整数常量
    int* arr    = (int[3]){10, 20, 30}; //整数数组
}

void t1() {
    // 3x3数组
    int(*(arr1[])) = {(int[]){0, 1, 2}, (int[]){3, 4, 5}, (int[]){6, 7, 8}};
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            printf("arr1[%d][%d] Address: %p Value: %d\n", j, i, &arr1[j][i],
                   arr1[j][i]);
        }
        printf("\n");
    }
}
/*
arr1[0][0] Address: 0x16b472fb0 Value: 0
arr1[0][1] Address: 0x16b472fb4 Value: 1
arr1[0][2] Address: 0x16b472fb8 Value: 2

arr1[1][0] Address: 0x16b472fa0 Value: 3
arr1[1][1] Address: 0x16b472fa4 Value: 4
arr1[1][2] Address: 0x16b472fa8 Value: 5

arr1[2][0] Address: 0x16b472f90 Value: 6
arr1[2][1] Address: 0x16b472f94 Value: 7
arr1[2][2] Address: 0x16b472f98 Value: 8*/


void t2() {
    int(*(arr2[])) = {(int[]){0, 1, 2, 3}, (int[]){4, 5}, (int[]){6, 7, 8}};
    int row        = 0;
    for (int i = 0; i < 4; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i],
               arr2[row][i]);
    }
    printf("\n");
    row = 1;
    for (int i = 0; i < 2; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i],
               arr2[row][i]);
    }
    printf("\n");
    row = 2;
    for (int i = 0; i < 3; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i],
               arr2[row][i]);
    }
    printf("\n");
    /*
    layer1[0][0] Address: 0x16d7dafa8 Value: 0
    layer1[0][1] Address: 0x16d7dafac Value: 1
    layer1[0][2] Address: 0x16d7dafb0 Value: 2
    layer1[0][3] Address: 0x16d7dafb4 Value: 3

    layer1[1][0] Address: 0x16d7dafa0 Value: 4
    layer1[1][1] Address: 0x16d7dafa4 Value: 5

    layer1[2][0] Address: 0x16d7daf90 Value: 6
    layer1[2][1] Address: 0x16d7daf94 Value: 7
    layer1[2][2] Address: 0x16d7daf98 Value: 8
    */
}

/*
复合字面量在创建不规则数组时很有用，不过访问不规则数组的元素比较别扭，上面的例子就用了3个for循环。如果有一个单独的数组来维护每行的长度，那么这个例子就可以简化。你可以在C中创建不规则数组，不过要考虑好它能起的作用是否值得花费相应的精力。*/
int main(int argc, char const* argv[]) {
    // t0();
    // t1();
    t2();
    return 0;
}