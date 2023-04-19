#include <stdio.h>

int main() {
    int sum = 0, i = 0;
    char input[5];
    while (1) {
        scanf("%s", input);
        sum = 0;
        for (i = 0; input[i] != '\0'; i++) {
            sum = sum * 10 + input[i] - '0';
        }
        printf("input=%d\n", sum);
    }
}
/*
123
input=123
12345
input=123407
*/
