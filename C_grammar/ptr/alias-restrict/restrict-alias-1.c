#include <stdio.h>

void t1() { // weak alias
    int num = 5;
    int *p1 = &num;
    int *p2 = &num;
}

void t2() {
    // destory strong alias law
    float number           = 3.25f;
    unsigned int *ptrValue = (unsigned int *)&number;
    printf("%u\n", *ptrValue);
    unsigned int result = (*ptrValue & 0x80000000) == 0;
    printf("%u\n", result); // 1
}

void t3() {
    int num;
    const int *ptr1    = &num;
    int *ptr2          = &num;
    int volatile *ptr3 = &num;
}

int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}