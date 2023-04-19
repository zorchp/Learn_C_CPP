#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// robust
size_t stringLength(const char* string) {
    // size_t stringLength(char string[]) {
    // size_t stringLength(char* string) {
    size_t length = 0;
    while (*(string++)) { length++; }
    return length;
}
void t1() {
    char simpleArray[] = "simple string";
    char* simplePtr    = (char*)malloc(strlen("simple string") + 1);
    strcpy(simplePtr, "simple string");

    printf("%d\n", stringLength(simplePtr));

    printf("%d\n", stringLength(simpleArray));
    // printf("%d\n", stringLength(&simpleArray));//warning: expected 'char *'
    // but argument is of type 'char (*)[14]'
    printf("%d\n", stringLength(&simpleArray[0]));
    //============================================//
    printf("%p\n", (simplePtr));

    printf("%p\n", (simpleArray));
    printf("%p\n", (&simpleArray));
    printf("%p\n", (&simpleArray[0]));
    /*
    0x600002a0c040
    0x16b9c6fe8
    0x16b9c6fe8
    0x16b9c6fe8
    */
}

char* format(char* buffer, size_t size, const char* name, size_t quantity,
             size_t weight) {
    snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u", name, quantity,
             weight);
    return buffer;
}

void t2() {
    char buffer[100];
    size_t SIZE = 100;
    char* buffer1 =
        (char*)malloc(SIZE); //如果已经动态分配了内存, 就必须传入分配的大小,
                             //否则sizeof只读取一个字符
    printf("%s\n", format(buffer, sizeof(buffer), "Axle", 25, 45));
    printf("%s\n", format(buffer1, sizeof(buffer1), "Axle", 25, 45));
    printf("%s\n", format(buffer1, SIZE, "Axle", 25, 45));
    /*
    Item: Axle Quantity: 25 Weight: 45
    Item: A
    Item: Axle Quantity: 25 Weight: 45
    */
}
char* format1(char* buffer, size_t size, const char* name, size_t quantity,
              size_t weight) {
    char* formatString        = "Item: %s Quantity: %u Weight: %u";
    size_t formatStringLength = strlen(formatString) - 6;
    size_t nameLength         = strlen(name);
    size_t length             = formatStringLength + nameLength + 10 + 10 + 1;
    if (buffer == NULL) {
        buffer = (char*)malloc(length);
        size   = length;
    }
    snprintf(buffer, size, formatString, name, quantity, weight);
    return buffer;
}

void t3() {
    char* buffer  = NULL;
    size_t SIZE   = 100;
    char* buffer1 = (char*)malloc(SIZE);
    printf("%s\n", format1(buffer, 1, "Axle", 25, 45));
    printf("%s\n", format1(buffer1, sizeof(buffer1), "Axle", 25, 45));
    printf("%s\n", format1(buffer1, SIZE, "Axle", 25, 45));
    /*
    Item: Axle Quantity: 25 Weight: 45
    Item: A
    Item: Axle Quantity: 25 Weight: 45
    */
}
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}