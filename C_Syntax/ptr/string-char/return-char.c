#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* returnALiteral(int code) {
    switch (code) {
        case 100: return "Boston Processing Center";
        case 200: return "Denver Processing Center";
        case 300: return "Atlanta Processing Center";
        case 400: return "San Jose Processing Center";
    }
}

void t1() { returnALiteral(100); }

char* staticFormat(const char* name, size_t quantity, size_t weight) {
    static char buffer[64]; // 假设缓冲区足够大
    sprintf(buffer, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);
    return buffer;
}

void t2() {
    char* part1 = staticFormat("Axle", 25, 45);
    char* part2 = staticFormat("Piston", 55, 5);
    printf("%s\n", part1);
    printf("%s\n", part2);
    /*
    Item: Piston Quantity: 55 Weight: 5
    Item: Piston Quantity: 55 Weight: 5
    */
}


char* blanks(int number) {
    char* spaces = (char*)malloc(number + 1);
    for (int i = 0; i < number; i++) { spaces[i] = ' '; }
    spaces[number] = '\0';
    return spaces;
}

void t3() {
    // char *tmp = blanks(5);
    // printf("[%s]\n", blanks(5));//内存泄漏,未保存指针,用后只能有操作系统释放
    //安全的方法:
    char* tmp = blanks(5);
    printf("[%s]\n", tmp);
    free(tmp);
}
#define MAX_TAB_LENGTH 32
char* blanks1(int number) {
    char spaces[MAX_TAB_LENGTH]; //不分配在堆区,函数调用之后就释放
    int i;
    for (i = 0; i < number && i < MAX_TAB_LENGTH; i++) { spaces[i] = ' '; }
    spaces[i] = '\0';

    return spaces;
}

void t4() {}
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}