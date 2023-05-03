#include <stdio.h>


int main(int argc, char const* argv[]) {
    int num = 0x12345678;
    char* pc = (char*) &num;
    for (int i = 0; i < 4; i++) {
        printf("%p: %02x \n", pc, (unsigned char) *pc++);
    }
    /*小端序
    0x16b076fd1: 78
    0x16b076fd2: 56
    0x16b076fd3: 34
    0x16b076fd4: 12
    */
    return 0;
}