#include <cstdio>
#include <iostream>
namespace inheritance_without_polymorphism {
class Point2d {
public:
    Point2d(float x = 0.0, float y = 0.0) : _x(x), _y(y) {}

    float x() const { return _x; }
    float y() const { return _y; } // const 必须加, 因为传入的是常量引用

    void x(float n_x) { _x = n_x; }
    void y(float n_y) { _y = n_y; }

    void operator+=(const Point2d& rhs) {
        _x += rhs.x();
        _y += rhs.y();
    }

protected:
    float _x, _y;
};

// 这样设计的好处是可以把管理 x 和 y 坐标的程序代码局部化, 此外,
// 这个设计可以明显表现出两个抽象类之间的紧密关系,
class Point3d : public Point2d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        : Point2d(x, y), _z(z) {}
    float z() const { return _z; }
    void z(float n_z) { _z = n_z; }
    void operator+=(const Point3d& rhs) {
        Point2d::operator+=(rhs);
        _z += rhs.z();
    }

protected:
    float _z;
};

// 如果把一个类分成多个类, 会导致膨胀
class Concrete { // sizeof : 8
public:
    //
private:
    int val;         // 4bytes
    char c1, c2, c3; // 3, +1alignment
};
// 如果这样实现:
class Concrete1 { // 8
public:
    int val;
    char c1;
};
class Concrete2 : public Concrete1 { // 12
public:
    char c2;
};
// 由于存在"基类子对象在派生类中保持原样性"
class Concrete3 : public Concrete2 { // sizeof: 12
public:
    char c3;
};
} // namespace inheritance_without_polymorphism

void t1() {
    using namespace inheritance_without_polymorphism;
    // std::cout << sizeof(Concrete)<<'\n'; // 8
    // std::cout << sizeof(Concrete1) << '\n'; // 8
    // std::cout << sizeof(Concrete2) << '\n'; // 12
    // std::cout << sizeof(Concrete3) << '\n'; // 12
    //
    Concrete2* pc2;
    Concrete1 *pc1_1, *pc1_2; // 都可以指向前述三种类对象
    // pc1_1 = pc2;
    //==5648==ERROR: AddressSanitizer: memcpy-param-overlap: memory ranges
    //[0x000000000000,0x000000000008) and [0x000000000001, 0x000000000009)
    // overlap

    *pc1_2 = *pc1_1; // 此时c2 就被覆盖掉了
    // std::cout << pc2->c2;
}

namespace with_polymorphism {
// 如果想这样使用点类, 也就是多态所支持的弹性, 例如:

// p1 p2 可能是 Point2d 或者 Point3d
// void foo(Point2d& p1, Point2d& p2) {
//     // ...
//     p1 += p2;
// }

// 就需要花一些代价, 这是不可避免的.

class Point2d {
public:
    Point2d(float x = 0.0, float y = 0.0) : _x(x), _y(y) {}

    float x() const { return _x; }
    float y() const { return _y; } // const 必须加, 因为传入的是常量引用
    virtual float z() const { return 0.0; } // do nothing

    void x(float n_x) { _x = n_x; }
    void y(float n_y) { _y = n_y; }
    virtual void z(float) {}

    virtual void operator+=(const Point2d& rhs) {
        _x += rhs.x();
        _y += rhs.y();
    }

protected:
    float _x, _y;
};

class Point3d : public Point2d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        : Point2d(x, y), _z(z) {}
    float z() const { return _z; }
    void z(float n_z) { _z = n_z; }
    // 这里是 Point2d, 因为要支持多态, 使基类(Point2d)
    // 和派生类(Point3d)都可以使用同一份接口(+=)
    void operator+=(const Point2d& rhs) {
        Point2d::operator+=(rhs);
        _z += rhs.z();
    }

protected:
    float _z;
};
} // namespace with_polymorphism

void t2() {
    using namespace with_polymorphism;
    Point2d p2d(2.1, 2.2);
    Point3d p3d(3.1, 3.2, 3.3);
    p3d += p2d;
    printf("%.2f, %.2f, %.2f\n", p3d.x(), p3d.y(), p3d.z());
    // 5.20, 5.40, 3.30
}

namespace multi_inheritance {
using namespace with_polymorphism; // 直接用写好的 Point3d 和 Point2d
class Vertex {
public:
    virtual void f() {}

protected:
    Vertex* next;
};

class Vertex3d : public Point3d, public Vertex {
public:
    //
protected:
    float mumble;
};

/* 继承关系
Point2d   Vertex
    |      |
Point3d    |
    |      |
    Vertex3d
*/

void mumble(const Vertex&) {}
} // namespace multi_inheritance


void t3() {
    using namespace multi_inheritance;
    Vertex3d v;
    mumble(v); // 这样转换并不好
}

namespace virtual_inheritance {
// class ios {};
// class istream : public ios {};
// class ostream : public ios {};
// class iostream : public istream, public ostream {};
class ios {};
class istream : virtual ios {};
class ostream : virtual ios {};
class iostream : public istream, public ostream {};
} // namespace virtual_inheritance

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
