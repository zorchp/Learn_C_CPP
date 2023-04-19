#include <stdio.h>

#define PIN1 int*
typedef int* PIN2;

int main(int argc, char const* argv[]) {
    int a   = 1;
    PIN1 a1 = &a, b = a;
    PIN2 aa = &a, bb = &a;
    return 0;
}