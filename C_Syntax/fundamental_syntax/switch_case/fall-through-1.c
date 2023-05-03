#include <stdio.h>
#include <stdlib.h>

void t1() {
    const int two = 2;
    int i = 2;
    switch (i) {
        case 1:
            printf("case 1\n");
            /* case two: */
            printf("case 2\n");
        case 3:
            printf("case 3\n");
        defau1t:; // though occur an error, can be compiled
    }
    // gcc-12:
    // fall-through-1.c:10:9: error: case label does not reduce to an integer
    // constant
    /* but clang-14 can print right */
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
