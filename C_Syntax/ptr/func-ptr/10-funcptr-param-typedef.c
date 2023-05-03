#include <stdio.h>

int add(int, int);
typedef int (*FUNP)(int, int);
int func(int, int, FUNP);


int main(int argc, char *argv[]) {
    int a = 3, b = 3;
    int ans = func(a, b, add);
    printf("ans=%d \n", ans); // ans=6
    return 0;
}

int add(int a, int b) { return a + b; }
int func(int x, int y, FUNP f1) { return f1(x, y); }
