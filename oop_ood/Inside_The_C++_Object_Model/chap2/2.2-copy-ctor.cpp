#include <cstdio>


namespace when_call_copy_ctor {

class X {
public:
    X(){};
    ~X(){};
    X(const X &) {
        printf("copy %s\n", __func__);
    };
};

void foo(X x) {
}

X bar() {
    X x;
    // ...
    return x;
}

} // namespace when_call_copy_ctor


void t1() {
    using namespace when_call_copy_ctor;
    // CXX_FLAG: -fno-elide-constructors
    X x;
    X xx = x; //
    foo(x);
    auto xxx = bar();
    // copy X
    // copy X
    // copy X
}

namespace default_memberwise_initialization {

class String {
public:
    String() {
        printf("%s\n", __func__);
    }

private:
    char *str;
    int len;
};
} // namespace default_memberwise_initialization

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
