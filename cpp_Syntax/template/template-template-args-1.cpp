#include <iostream>
#include <memory>

using namespace std;

template <typename T, template <typename> class SmartPtr>
class XCls {
private:
    SmartPtr<T> sp;

public:
    XCls() : sp(new T) {}
};

void t1() {
    XCls<string, shared_ptr> p1; //
    // XCls<string, unique_ptr> p2; //
    // XCls<string, weak_ptr> p3;   //
    XCls<string, auto_ptr> p4; // run in std C++11
    // warning: 'auto_ptr<std::string>' is deprecated
    // [-Wdeprecated-declarations]
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}