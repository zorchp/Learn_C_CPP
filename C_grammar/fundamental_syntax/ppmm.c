#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int a=10;
    int b=a++;
    printf("a=%d\n", a);
    printf("b=%d\n", b);
    return 0;
}
