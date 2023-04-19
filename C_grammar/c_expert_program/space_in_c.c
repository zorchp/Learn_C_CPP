#include <stdio.h>
void t1() {
    int a = 10, b = 20;
    // int c = a + ++b;//a=10, b=21, c=31
    int c = a++ + b; // a=11, b=20, c=30
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    /* ANSI C规定了一种逐渐为人所熟知的“maximal munch
     * strategy”（最大一口策略）。这种策略表示，如果下一个标记有超过一种的解释方案，
     * 编译器将选取能组成最长字符序列的方案。*/
}

void t2() {
    int a = 1, b = 2, c = a++ + ++b; // a=2, b=3, c=4
    // int a = 1, b = 2, c = a++ ++ +b; // error: lvalue required as increment
    // operand
    printf("a=%d, b=%d, c=%d\n", a, b, c);
}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}