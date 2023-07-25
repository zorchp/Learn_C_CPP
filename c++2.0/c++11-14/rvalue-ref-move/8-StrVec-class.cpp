#include <iostream>
#include <string>
#include <vector>


using namespace std;
using STRP = string *;

class StrVec {
public:
    StrVec() : elem(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);                // copy ctor
    StrVec &operator=(const StrVec &);     // copy assign
    StrVec(StrVec &&) noexcept;            // move ctor
    StrVec &operator=(StrVec &&) noexcept; // move assign
    ~StrVec();

    void push_back(const string &); // copy elem
    size_t size() const { return first_free - elem; }
    size_t capacity() const { return cap - elem; }
    STRPbegin() const { return elem; }
    STRPend() const { return first_free; }

private:
    static allocator<string> alloc;
    pair<STRP, STRP> alloc_n_copy(
        const STRP, const STRP); //分配内存,拷贝一个给定范围中的元素
    void free();                 //销毁构造的元素并释放内存
    void reallocate();           //内存用完之后分配新内存
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    } //保证StrVec至少有容纳一个新元素的空间

private:
    STRP elem, first_free,
        cap; //首元素指针,最后一个实际元素之后的位置指针,分配的内存末尾之后的位置指针
};


void StrVec::push_back(const string &s) {
    chk_n_alloc(); //确保有空间容纳新元素
    // first_free指向的元素中构造s的副本
    alloc.construct(first_free++,
                    s); // first_free当前值构造新对象,然后指向下一个未构造的元素
}

pair<STRP, STRP> StrVec::alloc_n_copy(const STRP b, const STRP e) {
    //分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}


StrVec::StrVec(StrVec &&s) noexcept
    : elem(s.elem), first_free(s.first_free), cap(s.cap) {
    s.elem = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elem = rhs.elem;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elem = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


void t1() { StrVec sv; }

int main(int argc, char const *argv[])
{
    t1();
    return 0;
}