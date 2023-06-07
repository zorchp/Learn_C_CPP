#include <cstdio>
// extern "C" {
typedef struct P {
    int a;
    double b;
    char c;
} p;

void t1() {
    p p1{.a = 12, .b = 1., .c = 97};

    p p2;
    p2 = p1; // 可以直接赋值
    printf("%d\n", p2.a);
    printf("%f\n", p2.b);
    printf("%c\n", p2.c);
}
typedef struct Q {
    int a;
    double b;
    char* s;
    p* p1;
} q;
void t2() {
    q q1{.a = 12, .b = .0};
    char ss[] = "你好";
    q1.s = ss;
    p p1{.a = 10};
    q1.p1 = &p1;
    q q2;
    q2 = q1; // 可以直接赋值
    printf("%d\n", q2.a);
    printf("%f\n", q2.b);
    printf("%s\n", q2.s);
    printf("p1.a=%d\n", q2.p1->a); // 你好
}

void t3() {
    //
}
// }
int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}