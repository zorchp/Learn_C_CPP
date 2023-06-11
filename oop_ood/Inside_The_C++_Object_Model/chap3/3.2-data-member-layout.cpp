#include <iostream>
#include <list>
#include <cassert>

class Point3d {
public:
    //
private:
    float x;
    static std::list<Point3d*>* freeList;

public:
    float y;
    static const int chunkSize = 20;

public:
    float z;
};
void t1() {
    std::cout << sizeof(Point3d) << '\n'; // 12, just 3*4(float), not static obj
    Point3d p;
    std::cout << sizeof(p); // 12
}


template <class class_type, class data_type1, class data_type2>
char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2) {
    assert(mem1 != mem2);
    return mem1 < mem2 ? "member 1 occurs first" : "member 2 occurs first";
}


void t2() {
    Point3d p;
    p.y = 1.2;
    std::cout << &Point3d::y << '\n';
    std::cout << &p.y << '\n';
    std::cout << &p << '\n';
    // 1
    // 0x16ba429a4
    // 0x16ba429a0

    // error
    // std::cout << access_order(&Point3d::z, &Point3d::y);
    //
}
int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
