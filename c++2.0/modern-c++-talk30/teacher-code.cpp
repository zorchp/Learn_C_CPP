#include <utility> // std::swap
#include <iostream>

class shared_count {
public:
    shared_count() noexcept : count_(1) {}
    void add_count() noexcept { ++count_; }
    long reduce_count() noexcept { return --count_; }
    long get_count() const noexcept { return count_; }

private:
    long count_;
};

template <typename T>
class smart_ptr {
public:
    template <typename U>
    friend class smart_ptr;
    explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {
        printf("smart_ptr(): %p\n", this);
        if (ptr) {
            shared_count_ = new shared_count();
        }
    }
    ~smart_ptr() {
        if (ptr_ && !shared_count_->reduce_count()) {
            printf("~smart_ptr(): %p\n", this);
            delete ptr_;
            delete shared_count_;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other) noexcept {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(smart_ptr<U>&& other) noexcept {
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other, T* ptr) noexcept {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    smart_ptr& operator=(smart_ptr rhs) noexcept {
        rhs.swap(*this);
        return *this;
    }
    T* get() const noexcept { return ptr_; }
    long use_count() const noexcept {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }
    void swap(smart_ptr& rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }
    T& operator*() const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    operator bool() const noexcept { return ptr_; }

private:
    T* ptr_;
    shared_count* shared_count_;
};


template <typename T>
void swap(smart_ptr<T>& lhs, smart_ptr<T>& rhs) noexcept {
    lhs.swap(rhs);
}
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
template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
class P { // for test
public:
    P() : x() { puts("P()"); }
    ~P() { puts("~P()"); }

    int x;
};

class shape {
public:
    virtual ~shape() {}
};
class circle : public shape {
public:
    ~circle() { puts("~circle()"); }
};
void t1() {
    smart_ptr<circle> ptr1(new circle());
    printf("use count of ptr1 is %ld\n", ptr1.use_count());
    smart_ptr<shape> ptr2;
    // smart_ptr<shape> ptr2(ptr1);
    printf("use count of ptr2 was %ld\n", ptr2.use_count());
    ptr2 = ptr1;
    printf("use count of ptr1 is now %ld\n", ptr1.use_count());
    printf("use count of ptr2 is now %ld\n", ptr2.use_count());
    if (ptr1) {
        puts("ptr1 is not empty");
    }
}

void t2() {
    smart_ptr<P> p1(new P);
    smart_ptr<P> p3;
    printf("p1=%ld, p3=%ld\n", p1.use_count(), p3.use_count());
    smart_ptr<P> p2(p1);
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    p3 = p1;
    printf("p1=%ld, p2=%ld, p3=%ld\n", p1.use_count(), p2.use_count(),
           p3.use_count());
    // p1->x = 12;
    // // same address
    // std::cout << p1.get() << std::endl;
    // std::cout << p2.get() << std::endl;
    // std::cout << p3.get() << std::endl;
    // // same value
    // std::cout << p1->x << std::endl;
    // std::cout << p2->x << std::endl;
    // std::cout << p3->x << std::endl;
}

int main(int argc, char const* argv[]) {
    t1();
    // t2();
    return 0;
}