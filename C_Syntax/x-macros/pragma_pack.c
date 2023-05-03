#include <stdio.h>


void t1() {
#pragma pack(2)

    struct _stu1 {
        char name[20]; // 20
        char num[10];  // 10
        int score;     // 4
        char sex;      // 1
    } stu1;            // 35->36

    printf("str1占用内存的大小为:%d个字节\n", sizeof(stu1));

#pragma pack() // reset to 4
    struct _stu2 {

        char name[20];
        char num[10];
        int score;
        char sex;
    } stu2; // 35->40
    printf("str2占用内存的大小为:%d个字节\n", sizeof(stu2));
    /*
    str1占用内存的大小为:36个字节
str2占用内存的大小为:40个字节
*/
}

void t2() {
#pragma pack(push)
#pragma pack(2)

    struct _stu1 {
        char name[20];
        char num[10];
        int score;
        char sex;
    } stu1;

    printf("str1占用内存的大小为:%d个字节\n", sizeof(stu1));

#pragma pack(pop)

    struct _stu2 {
        char name[20];
        char num[10];
        int score;
        char sex;
    } stu2;

    printf("str2占用内存的大小为:%d个字节\n", sizeof(stu2));
    /*
    str1占用内存的大小为:36个字节
str2占用内存的大小为:40个字节*/
}

int main(int argc, char* argv) {
// t1();
    t2();
    return 0;
}