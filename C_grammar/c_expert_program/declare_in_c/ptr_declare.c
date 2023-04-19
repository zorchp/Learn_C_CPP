#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int p = 10;
    char(*j)[20]; /* j是一个指向数组的指针，数组内有20个char元素*/
    j = (char(*)[20])malloc(20);
    // j = (char *[20])malloc(20);//error: cast specifies array type
    return 0;
}