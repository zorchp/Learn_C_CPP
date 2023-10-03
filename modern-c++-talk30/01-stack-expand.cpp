#include <cstdio>
class Obj {
public:
    Obj() { puts("Obj()"); }
    ~Obj() { puts("~Obj()"); }
};

void foo(int n) {
    Obj obj;
    if (n == 42) throw "life, the universe and everything";
}

int main(int argc, char *argv[]) {
    try {
        foo(41);
        foo(42);
    } catch (const char *s) {
        puts(s);
    }
    return 0;
}
