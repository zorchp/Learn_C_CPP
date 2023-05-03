#include <stdio.h>
#include <stdlib.h>


void t1() {
    int rows = 2;
    int columns = 5;
    /*首先分配“外层”数组，然后分别用malloc语句为每一行分配。*/
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("matrix[%d][%d] Address: %p Value: %d\n", i, j,
                   &matrix[i][j], matrix[i][j]);
    }
    //内存不连续
    /*
    matrix[0][0] Address: 0x600002619100 Value: 0
    matrix[0][1] Address: 0x600002619104 Value: 0
    matrix[0][2] Address: 0x600002619108 Value: 0
    matrix[0][3] Address: 0x60000261910c Value: 0
    matrix[0][4] Address: 0x600002619110 Value: 0//don't continue
    matrix[1][0] Address: 0x600002619120 Value: 0
    matrix[1][1] Address: 0x600002619124 Value: 0
    matrix[1][2] Address: 0x600002619128 Value: 0
    matrix[1][3] Address: 0x60000261912c Value: 0
    matrix[1][4] Address: 0x600002619130 Value: 0
    */
}

void t2() {
    int rows = 2;
    int columns = 5;
    int **matrix = (int **)malloc(rows * sizeof(int *));
    matrix[0] = (int *)malloc(rows * columns * sizeof(int));
    for (int i = 1; i < rows; i++) matrix[i] = matrix[0] + i * columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("matrix[%d][%d] Address: %p Value: %d\n", i, j,
                   &matrix[i][j], matrix[i][j]);
    }
    /*
    matrix[0][0] Address: 0x600001250270 Value: 0
    matrix[0][1] Address: 0x600001250274 Value: 0
    matrix[0][2] Address: 0x600001250278 Value: 0
    matrix[0][3] Address: 0x60000125027c Value: 0
    matrix[0][4] Address: 0x600001250280 Value: 0//continuous
    matrix[1][0] Address: 0x600001250284 Value: 0
    matrix[1][1] Address: 0x600001250288 Value: 0
    matrix[1][2] Address: 0x60000125028c Value: 0
    matrix[1][3] Address: 0x600001250290 Value: 0
    matrix[1][4] Address: 0x600001250294 Value: 0
    */
}

void t3() {
    int rows = 2;
    int columns = 5;
    // 相当于一维数组
    int *matrix = (int *)malloc(rows * columns * sizeof(int));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("matrix[%d][%d] Address: %p Value: %d\n", i, j,
                   &matrix[i * columns + j], matrix[i * columns + j]);
    }
    /*
    matrix[0][0] Address: 0x600002444270 Value: 0
    matrix[0][1] Address: 0x600002444274 Value: 0
    matrix[0][2] Address: 0x600002444278 Value: 0
    matrix[0][3] Address: 0x60000244427c Value: 0
    matrix[0][4] Address: 0x600002444280 Value: 0
    matrix[1][0] Address: 0x600002444284 Value: 0
    matrix[1][1] Address: 0x600002444288 Value: 0
    matrix[1][2] Address: 0x60000244428c Value: 0
    matrix[1][3] Address: 0x600002444290 Value: 0
    matrix[1][4] Address: 0x600002444294 Value: 0
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}