#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    auto x = 10.23;
    printf("%d\n", 10 < x);
    printf("%d\n", 10 == x); // 说明都转换成了 Double, 而不是向下转型为 int
    // who cast to who?
    // suppose: down cast
    printf("%d\n", 10 <= (int)x);
    printf("%d\n", (double)10 < x);
    return 0;
}
