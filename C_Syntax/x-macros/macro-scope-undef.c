#include <stdio.h>

#define N 9

int main() {
    int i, a[N];
    for (i = 0; i < N; i++) {
        a[i] = i;
        printf("a[%d]=%d\t", i, a[i]);
        if ((i + 1) % 3 == 0) printf("\n");
    }

    // #undef N
    printf("%d\n", N);
    /*
    a[0]=0  a[1]=1  a[2]=2
    a[3]=3  a[4]=4  a[5]=5
    a[6]=6  a[7]=7  a[8]=8
    9*/
    return 0;
}