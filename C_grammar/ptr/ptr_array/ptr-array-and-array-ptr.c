#include <stdio.h>

int main(int argc, char *argv[]) {
    int arr[4][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int(*p1)[4]; //数组指针, 指向一个有四个元素的数组的指针,本质是指针
    int *p2[4]; //指针数组, 本质是一个数组,存放指针
    int i, j, k;

    p1 = arr; //指向第一个4元素一维数组(首地址)
    printf("%p\n", p1);
    printf("%p\n", &p1);
    printf("%p\n", p1 + 1); //每次过一个一维4个元素的数组(size=4*4=16)
    printf("%p\n", &p1 + 1); //每次过一个size=8的指针位置
    /*
    0x16d54f008
    0x16d54efd0
    0x16d54f018
    0x16d54efd8
    */

    printf("使用数组指针的方式访问二维数组arr\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("arr[%d][%d]=%d\t", i, j, *(*(p1 + i) + j));
        }
        printf("\n");
    }

    printf("\n使用指针数组的方式访问二维数组arr\n");

    for (k = 0; k < 4; k++) p2[k] = arr[k];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("arr[%d][%d]=%d\t", i, j, *(p2[i] + j));
        }
        printf("\n");
    }
    /*
    使用数组指针的方式访问二维数组arr
    arr[0][0]=0 arr[0][1]=1 arr[0][2]=2 arr[0][3]=3
    arr[1][0]=4 arr[1][1]=5 arr[1][2]=6 arr[1][3]=7
    arr[2][0]=8 arr[2][1]=9 arr[2][2]=10    arr[2][3]=11
    arr[3][0]=12    arr[3][1]=13    arr[3][2]=14    arr[3][3]=15

    使用指针数组的方式访问二维数组arr
    arr[0][0]=0 arr[0][1]=1 arr[0][2]=2 arr[0][3]=3
    arr[1][0]=4 arr[1][1]=5 arr[1][2]=6 arr[1][3]=7
    arr[2][0]=8 arr[2][1]=9 arr[2][2]=10    arr[2][3]=11
    arr[3][0]=12    arr[3][1]=13    arr[3][2]=14    arr[3][3]=15
    */
    return 0;
}