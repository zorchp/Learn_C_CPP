#include <stdio.h>

struct item {
    int a;
    double b;
};

int main(int argc, char const *argv[]) {
    item ii[10]; // only ok in C++
    return 0;
}