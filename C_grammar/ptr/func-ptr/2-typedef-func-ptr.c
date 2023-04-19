#include <stdio.h>

typedef int (*t_somefunc)(int, int); // function ptr

int product(int u, int v) { return u * v; }

void t1() {
    t_somefunc afunc = product;
    printf("afunc=%p\n", afunc);
    printf("&afunc=%p\n", &afunc);
    printf("*afunc=%p\n", *afunc);
    /*
    afunc=0x1006dfe48
    &afunc=0x16f723080
    *afunc=0x1006dfe48
    x2=56088
    */
    int x2 = afunc(123, 456);     // call product() to calculate 123*456
    int x3 = (*afunc)(123, 456);  // call product() to calculate 123*456
    int x4 = (*&afunc)(123, 456); // call product() to calculate 123*456
    printf("x2=%d\n", x2);
    printf("x3=%d\n", x3);
    printf("x4=%d\n", x4);
    /*
    x2=56088
    x3=56088
    x4=56088
    */
}
int main(int argc, char const *argv[]) {
    t1();
    return 0;
}