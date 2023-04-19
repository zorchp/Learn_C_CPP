#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b = 1, c = 2;
    a = b = c;
    printf("a=%d, b=%d, c=%d\n", a, b, c); // a=2, b=2, c=2
    return 0;
    /*
    所有的赋值符（包括复合赋值符）都具有右结合性，就是说表达式中最右边的操作最先执行，然后从右到左依次执行。这样，c先赋值给b，然后b再赋值给a，最终a的值是2。类似地，具有左结合性的操作符（如位操作符“&”和“|”）则是从左至右依次执行。*/
}