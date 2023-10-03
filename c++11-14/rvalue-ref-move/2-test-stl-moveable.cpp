#include <bits/stdc++.h>
using namespace std;
/*
move 是指针的浅拷贝
右值被拷贝之后不能再用了
*/


class MyString {
public:
    static size_t DCtor; // default ctor
    static size_t Ctor;  // ctor
    static size_t CCtor; // copy-ctor
    static size_t CAsgn; // copy-assign
    static size_t MCtor; // move-ctor
    static size_t MAsgn; // move-assign
    static size_t Dtor;  // dtor
private:
    char* _data;
    size_t _len;
    void _init_data(const char* s) {
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }

public:
    // default-ctor
    MyString() : _data(nullptr), _len(0) { ++DCtor; }
    // ctor
    MyString(const char* p) : _len(strlen(p)) {
        ++Ctor;
        _init_data(p);
    }
    // copy ctor
    MyString(const MyString& str) : _len(str._len) {
        ++CCtor;
        _init_data(str._data);
    }
    //=========== move ctor ================
    MyString(MyString&& str) noexcept : _data(str._data), _len(str._len) {
        ++MCtor;
        str._len  = 0;
        str._data = nullptr; // important
    }
    //======================================
    // copy-assign
    MyString& operator=(const MyString& str) {
        ++CAsgn;
        // ----自我赋值检查-------------
        if (this != &str) {
            if (_data) delete _data;
            _len = str._len;
            _init_data(str._data); // copy
        } else {
        }
        //-----------------------
        return *this;
    }
    // move-assign
    MyString& operator=(MyString&& str) noexcept {
        ++MAsgn;
        // ----自我赋值检查-------------
        if (this != &str) {
            if (_data) delete _data;
            _len      = str._len;  // move
            _data     = str._data; // move
            str._len  = 0;
            str._data = nullptr;
        }
        //-----------------------
        return *this;
    }
    // dtor
    virtual ~MyString() {
        ++Dtor;
        if (_data) { delete _data; }
    }
    // reload compare operator
    bool operator<(const MyString& rhs) const { // set
        return string(this->_data) < string(rhs._data);
    }
    bool operator==(const MyString& rhs) const { // set
        return string(this->_data) == string(rhs._data);
    }
    char* get() const { return _data; }
};

// static var outline init
size_t MyString::DCtor{}; // default ctor
size_t MyString::Ctor{};  // ctor
size_t MyString::CCtor{}; // copy-ctor
size_t MyString::CAsgn{}; // copy-assign
size_t MyString::MCtor{}; // move-ctor
size_t MyString::MAsgn{}; // move-assign
size_t MyString::Dtor{};  // dtor

// output func
template <typename T>
void output_static_data(const T& myStr) {
    cout << typeid(myStr).name() << "--" << endl;
    cout << " CCtor=" << T::CCtor << " MCtor=" << T::MCtor
         << " CAsgn=" << T::CAsgn << " MAsgn=" << T::MAsgn
         << " Dtor=" << T::Dtor << " Ctor=" << T::Ctor << " DCtor=" << T::DCtor
         << endl;
}


template <typename M>
void test_moveable(M c, long& value) {
    char buf[10];
    typedef typename iterator_traits<typename M::iterator>::value_type Vtype;
    clock_t start = clock();

    for (long i = 0; i < value; i++) {
        snprintf(buf, 10, "%d", rand());
        c.insert(c.end(), Vtype(buf));
    }
    cout << "construction, milli-seconds: " << (clock() - start) << endl;
    cout << "size()=" << c.size() << endl;
    output_static_data(*(c.begin()));
    M c1(c);       // copy
    M c2(move(c)); // move copy
    c1.swap(c2);
}


void t1() {
    long value = 3000000L;
    test_moveable(vector<MyString>(), value);
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}