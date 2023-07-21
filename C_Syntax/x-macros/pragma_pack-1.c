#include <stdio.h>

; // for depress clang warning
#pragma pack(push)
#pragma pack(4)
struct C {
    double d; // 8
    char b;   // 1
    int a;    // 4
    short c;  // 2
};

// #pragma pack(pop)

#pragma pack(pop) // returun to default aligned
struct B {
    double d; // 8
    char b;   // 1
    int a;    // 4
    short c;  // 2
};
int main(int arg, char *argv[]) {
    printf("%ld\n", sizeof(struct C));
    printf("%ld\n", sizeof(struct B));
    return 0;
}
