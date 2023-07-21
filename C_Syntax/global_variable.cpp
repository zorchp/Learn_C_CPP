#include <cstdio>
int a, b;
void fun() {
    a = 100, b = 200;
}

int main(int argc, char *argv[]) {
    int a = 5, b = 7;
    fun();
    printf("%d,%d\n", a, b);

    return 0;
}
