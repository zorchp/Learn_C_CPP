#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 1, b = 2;
    int c;
    c = a /
        /*
  // */ b;
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    // a=1, b=2, c=0
    return 0;
}