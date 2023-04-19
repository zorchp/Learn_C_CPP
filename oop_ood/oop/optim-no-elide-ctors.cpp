
#include <stdio.h>
 
class A {
public:
    A(int val) {
        puts("A(int)");
        d = val;
    }
    A(A&& a) {
        puts("A(A&&)");
        d = a.d;
    }
    A(A& a) {
        puts("A(A&)");
        d = a.d;
    }
    ~A() {}
private:
    int d;
};
A create_A(int val) {
    A a(val);
    printf("create_A()::&a = %p\n", &a);
    return a;
}
int main(void) {
    A a{create_A(5)};
    printf("main()::&a = %p\n", &a);
 
    return 0;
}
