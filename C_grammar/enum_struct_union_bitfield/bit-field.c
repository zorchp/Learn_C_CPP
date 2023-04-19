#include <stdio.h>

void t1() {
    struct bs {
        unsigned m;
        unsigned n : 4;
        unsigned char ch : 6;
    } a = {0xad, 0xE, '$'};
    //第一次输出
    printf("%#x, %#x, %c\n", a.m, a.n, a.ch);
    //更改值后再次输出
    a.m  = 0xb8901c;
    a.n  = 0x2d;
    a.ch = 'z';
    printf("%#x, %#x, %c\n", a.m, a.n, a.ch);
    /*0xad, 0xe, $
    0xb8901c, 0xd, :
    */
}
/*
对于 n 和 ch，第一次输出的数据是完整的，第二次输出的数据是残缺的。

第一次输出时，n、ch 的值分别是 0xE、0x24（'$' 对应的 ASCII 码为
0x24），换算成二进制是 1110、10 0100，都没有超出限定的位数，能够正常输出。

第二次输出时，n、ch 的值变为 0x2d、0x7a（'z' 对应的 ASCII 码为
0x7a），换算成二进制分别是 10 1101、111
1010，都超出了限定的位数。超出部分被直接截去，剩下 1101、11
1010，换算成十六进制为 0xd、0x3a（0x3a 对应的字符是 :）。
*/


int main() {
    t1();
    return 0;
}