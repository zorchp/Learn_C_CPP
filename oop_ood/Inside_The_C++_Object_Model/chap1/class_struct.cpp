// 合法的代码:
class A;
struct A {
    int x;
};

// 矛盾, 但是实际上并不报错
static int a;
extern int a;

int main(int argc, char *argv[]) {
    //
    return 0;
}
