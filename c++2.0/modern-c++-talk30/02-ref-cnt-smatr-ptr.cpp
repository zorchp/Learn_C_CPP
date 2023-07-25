#include <cstdio>
#include <cassert>
#include <utility> //std::swap
#include <iostream>

class P { // for test
public:
    P() : x() { puts("P()"); }
    ~P() { puts("~P()"); }

    int x;
};

class shared_count {
public:
    shared_count() : count_(1) {}  // 初始化为 1
    void add_count() { ++count_; } // 增加计数
    long reduce_count() {
        return --count_;
    } // 减少计数, 返回以供调用者判断是否删除对象
    long get_count() const { return count_; }

private:
    long count_;
};

template <typename T>
class smart_ptr {
    template <typename U>
    friend class smart_ptr;

public:
    explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {
        puts("smart_ptr()");
        if (ptr) {
            shared_count_ = new shared_count;
        }
    }

    ~smart_ptr() {
        puts("~smart_ptr()");
        if (ptr_ && !shared_count_->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }

    void swap(smart_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    smart_ptr(const smart_ptr& rhs) { // shared, use copy ctor
        puts("smart_ptr copy-ctor");
        ptr_ = rhs.ptr_;
        if (ptr_) {
            rhs.shared_count_->add_count();
            shared_count_ = rhs.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& rhs) { // shared, use copy ctor
        puts("smart_ptr copy-ctor");
        ptr_ = rhs.ptr_;
        if (ptr_) {
            rhs.shared_count_->add_count();
            shared_count_ = rhs.shared_count_;
        }
    }

    template <typename U>
    smart_ptr(smart_ptr<U>&& rhs) {
        puts("smart_ptr move-ctor");
        ptr_ = rhs.ptr_;
        if (ptr_) {
            shared_count_ = rhs.shared_count_;
            rhs.ptr_ = nullptr;
        }
    }
    smart_ptr& operator=(smart_ptr rhs) noexcept {
        puts("smart_ptr copy assignment");
        rhs.swap(*this);
        return *this;
    }
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    operator bool() const { return ptr_; } // for nullptr check

    long use_count() const {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

    // for cast
    template <typename U>
    smart_ptr(const smart_ptr<U>& other, T* ptr) noexcept {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

private:
    T* ptr_;
    shared_count* shared_count_;
};

template <typename T>
void swap(smart_ptr<T>& lhs, smart_ptr<T>& rhs) noexcept {
    puts("call a.swap(b)");
    lhs.swap(rhs);
}


void t1() {
    smart_ptr<P> p1(new P);
    smart_ptr<P> p3;
    printf("p1=%ld, p3=%ld\n", p1.use_count(), p3.use_count());
    smart_ptr<P> p2(p1);
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    p3 = p1;
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    p1->x = 12;
    // same address
    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;
    std::cout << p3.get() << std::endl;
    // same value
    std::cout << p1->x << std::endl;
    std::cout << p2->x << std::endl;
    std::cout << p3->x << std::endl;
    // P()
    // p1=2, p2=2, p3=0
    // p1=3, p2=3, p3=3
    // ~P()
}

void t2() {
    smart_ptr<P> p1(new P);
    smart_ptr<P> p3(new P);
    auto p2(p1);
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    p3 = p2;
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    // P()
    // P()
    // p1=2, p2=2, p3=1
    // ~P()
    // p1=3, p2=3, p3=3
    // ~P()
}

class shape {
public:
    virtual ~shape() {}
};

class circle : public shape {
public:
    ~circle() { puts("~circle"); }
};

void t3() {
    smart_ptr<circle> p1(new circle);
    printf("p1=%ld\n", p1.use_count());
    smart_ptr<shape> p2;
    printf("p2=%ld\n", p2.use_count());
    p2 = p1;
    puts("copy assignment...");
    printf("p1=%ld\n", p1.use_count());
    printf("p2=%ld\n", p2.use_count());
    assert(p1);
    // p1=1
    // p2=0
    // smart_ptr &
    // copy assignment...
    // p1=2
    // p2=2
    // ~circle
}

// cast test:
template <typename T, typename U>
smart_ptr<T> static_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = static_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
template <typename T, typename U>
smart_ptr<T> reinterpret_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = reinterpret_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
template <typename T, typename U>
smart_ptr<T> const_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = const_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
// 上行转换(子类指针到父类指针)与 static_cast 一样(都进行类型检查)
// 下行转换(父类指针到子类指针)执行运行时类型检查(RTTI), 更加安全
template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

void t4() {
    smart_ptr<circle> p1(new circle);
    printf("p1=%ld\n", p1.use_count());
    smart_ptr<shape> p2;
    p2 = p1;
    printf("p2=%ld\n", p2.use_count());
    smart_ptr<circle> p3 = dynamic_pointer_cast<circle>(p2);
    printf("p3=%ld\n", p3.use_count());
}

int main(int argc, char* argv[]) {
    // t1();
    // t2();
    // t3();
    t4();
    return 0;
}
