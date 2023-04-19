#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
C用传统的argc和argv参数支持命令行参数。
第一个参数argc，是一个指定传递的参数数量的整数。
系统至少会传递一个参数，这个参数是可执行文件的名字。
第二个参数argv，通常被看做字符串指针的一维数组，每个指针引用一个命令行参数。
*/
int main(int argc, char* argv[]) {
    // int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) { printf("argv[%d] %s\n", i, argv[i]); }
}
/*
❯ ./pass 12 3 13
argv[0] ./pass
argv[1] 12
argv[2] 3
argv[3] 13
*/