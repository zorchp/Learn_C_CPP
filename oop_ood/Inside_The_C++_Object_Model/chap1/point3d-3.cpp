#include <iostream>
using namespace std;

// 参数化
template <class type>
class Point3d {
public:
    Point3d(type x = 0.0, type y = 0.0, type z = 0.0) : _x(x), _y(y), _z(z) {}
    type x() { return _x; }
    void x(type xval) { _x = xval; }

private:
    type _x, _y, _z;
};
