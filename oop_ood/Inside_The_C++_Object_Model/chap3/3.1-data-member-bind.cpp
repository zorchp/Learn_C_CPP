#include <iostream>
namespace test1 {


extern float x;
class Point3d {
public:
    Point3d(float, float, float);
    float X() const { return x; }
    // void X(float new_x) const { x = new_x; }

private:
    float x, y, z;
};
} // namespace test1


namespace test2 {
typedef int length;

class Point3d {
    // typedef float length; // 除非用在了这里, 否则会用全局 typedef

public:
    void mumble(length val) { _val = val; }
    length mumble() { return _val; }
    // void X(float new_x) const { x = new_x; }

private:
    typedef float length;
    length _val;
};

} // namespace test2

void t2() {
    using namespace test2;
    Point3d p;
    std::cout << typeid(p.mumble()).name();
    // i, 说明用了全局的 typedef 而不是类内的
}

int main(int argc, char *argv[]) {
    t2();
    return 0;
}
