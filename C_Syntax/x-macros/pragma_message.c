#include <stdio.h>
#define STR


int main(int argc, char const *argv[]) {
    printf("学习#pragma命令中message参数的使用!\n");
    // printf("%c", STR);
#ifdef STR
#pragma message("STR has already defined!")
#endif
    return 0;
}
/*
parama_test_1.c: In function 'main':
parama_test_1.c:6:9: note: '#pragma message: STR has already defined!'
    6 | #pragma message("STR has already defined!")
      |         ^~~~~~~
[Finished in 1.4s]
*/