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

void t1() {
    // 用这种方式(工厂方法)创建对象只能用指针或者引用形式,
    // 否则会出现对象切片(slice)
}

// base version, just use RAII, but:
// 1. just for shape, may use template
// 2. make shape_wrapper as ptr
// 3. copy shape_wrapper may exception

class shape_wrapper {
public:
    explicit shape_wrapper(shape* ptr = nullptr) : ptr_(ptr) {}
    ~shape_wrapper() { delete ptr_; }
    shape* get() const { return ptr_; }

private:
    shape* ptr_;
};

void foo() {
    shape_wrapper ptr_wrapper(create_shape(shape_type::circle));
    std::cout << ptr_wrapper.get();
}


int main(int argc, char* argv[]) {
    // t1();
    foo();
    return 0;
}
