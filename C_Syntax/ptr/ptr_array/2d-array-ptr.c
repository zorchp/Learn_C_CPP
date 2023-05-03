#include <stdio.h>

int main(int argc, char *argv[]) {
    int arr[4][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i;

    for (i = 0; i < 4; i++) {
        printf("使用arr+i求得二维数组arr第%d行的起始地址为:%p\n", i + 1,
               arr + i);
        printf("使用arr[i]求得二维数组arr第%d行的起始地址为:%p\n", i + 1,
               arr[i]);
        printf("使用*(arr+i)求得二维数组arr第%d行的起始地址为:%p\n", i + 1,
               *(arr + i));
        printf("使用&arr[i]求得二维数组arr第%d行的起始地址为:%p\n\n", i + 1,
               &arr[i]);
    }

    return 0;
    /*
    使用arr+i求得二维数组arr第1行的起始地址为:0x16b5eb028
    使用arr[i]求得二维数组arr第1行的起始地址为:0x16b5eb028
    使用*(arr+i)求得二维数组arr第1行的起始地址为:0x16b5eb028
    使用&arr[i]求得二维数组arr第1行的起始地址为:0x16b5eb028

    使用arr+i求得二维数组arr第2行的起始地址为:0x16b5eb038
    使用arr[i]求得二维数组arr第2行的起始地址为:0x16b5eb038
    使用*(arr+i)求得二维数组arr第2行的起始地址为:0x16b5eb038
    使用&arr[i]求得二维数组arr第2行的起始地址为:0x16b5eb038

    使用arr+i求得二维数组arr第3行的起始地址为:0x16b5eb048
    使用arr[i]求得二维数组arr第3行的起始地址为:0x16b5eb048
    使用*(arr+i)求得二维数组arr第3行的起始地址为:0x16b5eb048
    使用&arr[i]求得二维数组arr第3行的起始地址为:0x16b5eb048

    使用arr+i求得二维数组arr第4行的起始地址为:0x16b5eb058
    使用arr[i]求得二维数组arr第4行的起始地址为:0x16b5eb058
    使用*(arr+i)求得二维数组arr第4行的起始地址为:0x16b5eb058
    使用&arr[i]求得二维数组arr第4行的起始地址为:0x16b5eb058
    */
}