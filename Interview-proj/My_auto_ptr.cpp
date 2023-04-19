#include <iostream>
#include <vector>
using namespace std;


template <class T>
class auto_ptr {
public:
    // 显式构造函数
    explicit auto_ptr(T *p = 0) : pointee(p) {}

    // 拷贝构造成员模板
    template <class U>
    auto_ptr(auto_ptr<U> &rhs) : pointee(rhs.release()) {}

    // 仅在析构函数中调用 delete
    ~auto_ptr() { delete pointee; }

    // 拷贝赋值运算符成员模板
    template <class U>
    auto_ptr<T> &operator=(auto_ptr<U> &rhs) {
        if (this != &rhs) reset(rhs.release());
        return *this;
    }


    T &operator*() const { return *pointee; }
    T *operator->() const { return pointee; }

    // 返回裸指针
    T *get() const { return pointee; }

    T *release() {
        T *oldPointee = pointee;
        pointee = 0;
        return oldPointee;
    }

    void reset(T *p = 0) {
        if (pointee != p) {
            delete pointee;
            pointee = p;
        }
    }

private:
    T *pointee;
    template <class U>
    friend class auto_ptr; // 让所有其他 auto_ptr 都成为该 auto_ptr 的友元
};


void t1() {
    //
}


int main(int argc, char const *argv[]) {
    t1();
    return 0;
}