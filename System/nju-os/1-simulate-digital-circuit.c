#include <stdio.h>
#include <unistd.h>
#define REGS_FOREACH(_) _(X) _(Y)
#define RUN_LOGIC \
    X1 = !X && Y; \
    Y1 = !X && !Y;
#define DEFINE(X) static int X, X##1;
#define UPDATE(X) X = X##1;
#define PRINT(X) printf(#X " = %d; ", X);

/*
X'=~X cap Y;
Y'=~X cap ~Y;
*/
int main(int argc, char const *argv[]) {
    REGS_FOREACH(DEFINE);
    while (1) { // clock_period
        RUN_LOGIC;
        REGS_FOREACH(PRINT);
        REGS_FOREACH(UPDATE);
        putchar('\n');
        sleep(1);
    }
    /*
    X = 0; Y = 0;
    X = 0; Y = 1;
    X = 1; Y = 0;
    X = 0; Y = 0;
    X = 0; Y = 1;
    X = 1; Y = 0;
    X = 0; Y = 0;
    X = 0; Y = 1;
    X = 1; Y = 0;
    */
    return 0;
}

/*gcc -E
int main(int argc, char const *argv[]) {
    static int X, X1; static int Y, Y1;;
    while (1) {
        X1 = !X && Y; Y1 = !X && !Y;;
        printf("X"" = %d; ", X); printf("Y"" = %d; ", Y);;
        X = X1; Y = Y1;;
        putchar('\n');
        sleep(1);
    }
# 34 "1-simulate-digital-circuit.c"
    return 0;
}
*/
