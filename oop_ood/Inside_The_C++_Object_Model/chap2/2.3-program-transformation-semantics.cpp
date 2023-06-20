#include <cstdio>
#include <cstring>

class X {
public:
    X() {
        printf("%s\n", __FUNCTION__);
    }
    ~X() {
        printf("%s\n", __FUNCTION__);
    }
    X(const X &) {
        printf("%s(const X&)\n", __FUNCTION__);
    }
};

X foo() {
    X xx;
    //
    return xx;
}

void t1() {
    // foo(); //-fno-elide -constructors

    X x0;
    // 显式初始化
    // all Copy ctor
    X x1(x0);
    X x2 = x0;
    X x3 = X(x0);
}

void foo(X x0) {
    //
}

void t2() {
    X xx;
    foo(xx); // copy ctor
}

namespace NRV {
class test {
    friend test foo(double);

public:
    test() {
        memset(array, 0, 100 * sizeof(double));
    }
    inline test(const test &t) {
    }

private:
    double array[100];
};

test foo(double val) {
    test local;
    local.array[0] = val;
    local.array[99] = val;
    return local;
}
} // namespace NRV

void t3() {
    using namespace NRV;
    for (int cnt{}; cnt < 10000000; ++cnt) {
        test t = foo(double(cnt)); // 此时无法实施 NRV 优化
    }
}

class Shape {
public:
    Shape() {
        memset(this, 0, sizeof(Shape));
    }
    virtual ~Shape() {
    }
};

void t4() {
    Shape s1;
    // warning: destination for this 'memset' call is a pointer to dynamic class
    // 'Shape'; vtable pointer will be overwritten [-Wdynamic-class-memaccess]
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
