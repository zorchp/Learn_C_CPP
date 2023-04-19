#include <iostream>
using namespace std;

class Point3d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0)
        : _x(x), _y(y), _z(z) {}
    float x() const { return _x; }
    float y() const { return _y; }
    float z() const { return _z; }

    void x(float xval) { _x = xval; }

private:
    float _x, _y, _z;
};

inline ostream& operator<<(ostream& os, const Point3d& pt) {
    os << "(" << pt.x() << ", " << pt.y() << ", " << pt.z() << " )";
    return os;
}
int main(int argc, char* argv[]) {
    Point3d pt(1, 2, 3);
    cout << pt << endl;
    return 0;
}
