#include <cstdio>

#define num 5

void func();
int main(int argc, char *argv[]) {
    printf("%d", num);
    func();
    printf("%d", num);
    return 0;
}

void func() {
#undef num
#define num 1
    printf("%d ,in \n", num);
}
