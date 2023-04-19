#include <stdio.h>

#define n1 100
#define M (n1 * n1 + 3 * n1)

int main() {
    int sum, n;
    printf("Input a number: ");
    scanf("%d", &n);
    sum = 3 * M + 4 * M + 5 * M;
    printf("sum=%d\n", sum);
    return 0;
}