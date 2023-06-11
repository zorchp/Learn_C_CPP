#include <iostream>
#include <list>
#include <cassert>
class Point3d {
public:
    //
    float x;
    static std::list<Point3d*>* freeList;

public:
    float y;
    static const int chunkSize = 20;

public:
    float z;
};
Point3d origin, *pt = &origin;

void t1() {
    origin.x = 1.;
    pt->x = 2.;
    std::cout << origin.x << '\n'; // 2
    std::cout << pt->x << '\n';    // 2
}

void t2() {
    // origin.chunkSize==23;
    std::cout << (Point3d::chunkSize == 230); // 0
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
