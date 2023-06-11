#include <cstdio>
#include <cassert>
#include <iostream>


class Point3d {
public:
    Point3d() : x(12), y(23), z(34) {}
    virtual ~Point3d() {}

    static Point3d origin;
    float x;

private:
    float y;

public:
    float z;
};

Point3d Point3d::origin;

void t1() {
    // 取一个非静态数据成员的地址, 将会得到它在类中的偏移量
    printf("sizeof Point3d : %ld\n", sizeof(Point3d)); // 24
    printf("&Point3d::x = %p\n", &Point3d::x);         // 0x8
    // printf("&Point3d::y = %p\n", &Point3d::y);         // 0xc
    printf("&Point3d::z = %p\n", &Point3d::z); // 0x10
    // std::cout << &Point3d::x << '\n'; // 1
    // std::cout << &Point3d::y << '\n'; // 1
    // std::cout << &Point3d::z << '\n'; // 1
}

using fpp = float Point3d::*;
void t2() {
    fpp p1 = 0;
    fpp p2 = &Point3d::x;
    assert(p1 == p2); // Assertion failed: (p1 == p2), function t2,
}

void t3() {
    //
    // 取一个绑定于真正的类对象身上的数据成员的地址,
    // 将会得到该成员在内存中的真正地址
    Point3d p;
    p.x = 1.23;
    printf("%p\n", &Point3d::origin.z);
    printf("%p\n", &p); // 0x16d616a20
    // 中间差了一个 vptr(8), 和两个 float(4*2)=0x10
    printf("%p\n", &p.z); // 0x16d616a30
    // 通过偏移量获取值:
    printf("%f\n", *((float *)((char *)&p + 8)));
    printf("%f\n", *((float *)((char *)&p + 12))); // 这样私有成员也可以访问了
    printf("%f\n", *((float *)((char *)&p + 16)));
}

struct B1 {
    int v1;
};
struct B2 {
    int v2;
};
struct D : B1, B2 {
    int x;
};

void f1(int D::*dmp, D *pd) { //
    pd->*dmp = 1;
}

void f2(D *pd) {
    int B2::*bmp = &B2::v2;
    f1(bmp, pd);
}

void t4() {
    printf("%p\n", &B1::v1);
    printf("%p\n", &B2::v2);
    printf("%p\n", &D::v1);
    printf("%p\n", &D::v2);
    printf("%p\n", &D::x); // 8
}

int main(int argc, char *argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
