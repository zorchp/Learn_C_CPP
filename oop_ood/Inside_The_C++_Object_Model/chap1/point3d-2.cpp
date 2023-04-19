#include <iostream>
#include <limits>
using namespace std;

class Point {
public:
    Point(float x = 0.0) : _x(x) {}
    float x() { return _x; }
    void x(float xval) { _x = xval; }

protected:
    float _x;
};

class Point2d : public Point {
public:
    Point2d(float x = 0.0, float y = 0.0) : Point(x), _y(y) {}
    float y() { return _y; }
    void y(float yval) { _y = yval; }

protected:
    float _y;
};

class Point3d : public Point2d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        : Point2d(x, y), _z(z) {}
    float z() { return _z; }
    void z(float zval) { _z = zval; }

protected:
    float _z;
};
int main(int argc, char *argv[]) {
    Point3d pt(1, 2, 3);
    return 0;
}
