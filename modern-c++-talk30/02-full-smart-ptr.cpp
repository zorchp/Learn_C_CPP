#include <cstdio>
#include <cassert>
#include <iostream>

enum class shape_type { circle, triangle, rectangle };
class shape {};
class circle : public shape {};
class triangle : public shape {};
class rectangle : public shape {};

shape* create_shape(shape_type type) {
    switch (type) {
        case shape_type::circle:
            return new circle;
        case shape_type::rectangle:
            return new rectangle;
        case shape_type::triangle:
            return new triangle;
    }
    return nullptr;
}
class P {
public:
    P() : x() { puts("P()"); }
    ~P() { puts("~P()"); }

    int x;
};

namespace version1 {
template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {}
    ~smart_ptr() { delete ptr_; }
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    operator bool() const { return ptr_; } // for nullptr check

    T* release() {
        auto ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    // copy
    // 转移对象所有权, 但是容易出问题
    smart_ptr(smart_ptr& other) {
        ptr_ = other.release();
        puts("smart_ptr copy ctor");
    }
    smart_ptr& operator=(smart_ptr& rhs) {
        // generate temp obj, to call copy-ctor
        smart_ptr(rhs).swap(*this);
        puts("smart_ptr copy assignment operator");
        return *this;
    }

    void swap(smart_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T* ptr_;
};
void print(std::ostream& s, smart_ptr<P> p) { s << (*p).x << '\n'; }
} // namespace version1


void t1() {
    using namespace version1;

    smart_ptr<P> sp1(new P);
    smart_ptr<P> sp2(sp1);               // call copy ctor
    std::cout << sp1.get() << std::endl; // 0x0
    smart_ptr<P> sp3;
    sp3 = sp2;
    // P()
    // smart_ptr copy ctor
    // smart_ptr copy ctor
    // smart_ptr copy assignment operator
    // ~P()
}

void t11() {
    // 由于拷贝构造函数会转移对象的所有权, 所以如果传值会出现资源泄露
    using namespace version1;
    smart_ptr<P> p(new P);
    p->x = 10;
    print(std::cout, p); // 值传递
    // 此时 p 为空指针了
    assert(p.release() != nullptr);
    p->x = 10; // runtime error: member access within null pointer of type 'P'
}


namespace version2 {
template <typename T>
class smart_ptr {
public:
    explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {}
    ~smart_ptr() { delete ptr_; }
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    operator bool() const { return ptr_; } // for nullptr check

    T* release() {
        auto ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    // move ctor
    smart_ptr(smart_ptr&& other) { ptr_ = other.release(); }
    // implicit delete copy-ctor
    // implicit delete copy-assignment-operator
    smart_ptr& operator=(smart_ptr rhs) {
        rhs.swap(*this);
        return *this;
    }

    void swap(smart_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

private:
    T* ptr_;
};
void print(std::ostream& s, smart_ptr<P> p) { s << (*p).x << '\n'; }

} // namespace version2

void t2() {
    using namespace version2;
    smart_ptr<shape> p1(create_shape(shape_type::circle));
    // auto p2(p1);
    smart_ptr<shape> p3;
    // p3 = p1;
    p3 = std::move(p1);
    smart_ptr<shape> p4{std::move(p3)};
}

void t21() {
    using namespace version2;
    smart_ptr<P> p(new P);
    p->x = 10;
    // print(std::cout, p); // call error
    // error: call implicit delete copy-ctor
    //  此时 p 为空指针了
    assert(p.release() != nullptr);
    p->x = 10; // runtime error: member access within null pointer of type 'P'
}

int main(int argc, char* argv[]) {
    // t1();
    // t11();
    t2();
    return 0;
}
