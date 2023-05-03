#include <stdio.h>
int main()
{
    int n = 9;
     
    printf("Count of 1s in binary of %d is %d ",
           n, __builtin_popcount(n));
    //Count of 1s in binary of 5 is 2
    return 0;
}
