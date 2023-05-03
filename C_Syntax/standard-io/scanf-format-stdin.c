#include <stdio.h>
#include <string.h>

void t1() {
    int a, b;
    // 返回值是匹配的数量
    if (scanf("%d%d", &a, &b) != 2) printf("error\n");
    printf("%d, %d\n", a, b);
}

void t2() {
    int i, j;
    int n = scanf("%d%d", &i, &j);
    printf("i=%d\n", i);
    printf("j=%d\n", j);
    printf("n=%d\n", n);
    // 12 , 23
    // i=12
    // j=1
    // n=1
}
void t3() {
    // %[^,]
    char s[1000] = "ab,c,de";
    char ans[3];
    // scanf("%[^,]", s);
    int i = 0;
    while (~scanf("%[^,]", ans)) {
        if (getchar() == ',') printf("%s\n", ans);
        memset(ans, ' ', 3);
        // if (getchar() == '\n') printf("%s\n", ans);
    }
    printf("%s\n", ans);
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}