#include <stdio.h>
//几种声明方法, 前两种等价, 第三种不行
// void display2DArray(int [][5], int);
void display2DArray(int (*)[5], int); //这里括号是必须的
// void display2DArray(int* [5], int);


void t1() {
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("matrix[%d][%d] Address: %p Value: %d\n", i, j,
                   &matrix[i][j], matrix[i][j]);
        }
    }

    int(*pmatrix)[5] = matrix; //声明指针处理二维数组
    //这里括号是必须的,没有括号的话就只能声明一个指向5个元素数组的指针
    /*
    (*pmatrix)表达式声明了一个数组指针，上面的整条声明语句将pmatrix定义为一个指向二维数组的指针，该二维数组的元素类型是整数，每行有5个元素。如果我们把括号去掉就声明了5个元素的数组，数组元素的类型是整数指针。如果声明的列数不是5，用该指针访问数组的结果则是不可预期的。
    */
    printf("pmatrix:%p\n", pmatrix);
    printf("**(pmatrix):%d\n", **(pmatrix));
    printf("pmatrix[1]:%p\n", pmatrix[1]);
    printf("pmatrix+1:%p\n", pmatrix + 1);
    printf("**(pmatrix+1):%d\n", **(pmatrix + 1));
    printf("%lu\n", sizeof(matrix[0]));
    printf("%p %d\n", matrix[0] + 1, *(matrix[0] + 1));
    /*
    matrix[0][0] Address: 0x16d0a2fc8 Value: 1
    matrix[0][1] Address: 0x16d0a2fcc Value: 2
    matrix[0][2] Address: 0x16d0a2fd0 Value: 3
    matrix[0][3] Address: 0x16d0a2fd4 Value: 4
    matrix[0][4] Address: 0x16d0a2fd8 Value: 5
    matrix[1][0] Address: 0x16d0a2fdc Value: 6
    matrix[1][1] Address: 0x16d0a2fe0 Value: 7
    matrix[1][2] Address: 0x16d0a2fe4 Value: 8
    matrix[1][3] Address: 0x16d0a2fe8 Value: 9
    matrix[1][4] Address: 0x16d0a2fec Value: 10
    pmatrix:0x16d0a2fc8
    **(pmatrix):1
    pmatrix[1]:0x16d0a2fdc
    pmatrix+1:0x16d0a2fdc
    **(pmatrix+1):6
    20
    0x16d0a2fcc 2
    */
}

void display2DArray(int arr[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) { printf("%d\t", arr[i][j]); }
        printf("\n");
    }
}

void t2() {
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    display2DArray(matrix, 2);
}


void display2DArrayUnknownSize(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //不能用二维下标访问,因为指针未声明为二维数组
            // treat as 1d array
            printf("%d ", *(arr + (i * cols) + j));
            //可以用一维下标访问
            printf("%d ", (arr + i * cols)[j]);
        }
        printf("\n");
    }
}

void t3() {
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int *ptr         = &matrix[0][0]; //这里是一个整数数组的指针
    display2DArrayUnknownSize(ptr, 2, 5);
    // matrix是一个整数数组的指针
}

void display3DArray(int (*arr)[2][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            printf("{");
            for (int k = 0; k < 4; k++) { printf("%d ", arr[i][j][k]); }
            printf("}");
        }
        printf("\n");
    }
}
void t4() {
    int arr3d[3][2][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}},
                          {{9, 10, 11, 12}, {13, 14, 15, 16}},
                          {{17, 18, 19, 20}, {21, 22, 23, 24}}};
    display3DArray(arr3d, 3);
    /*
    {1 2 3 4 }{5 6 7 8 }
    {9 10 11 12 }{13 14 15 16 }
    {17 18 19 20 }{21 22 23 24 }
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}