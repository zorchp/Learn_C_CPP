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

class MyStrNoMove {
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
    MyStrNoMove() : _data(nullptr), _len(0) { ++DCtor; }
    // ctor
    MyStrNoMove(const char* p) : _len(strlen(p)) {
        ++Ctor;
        _init_data(p);
    }
    // copy ctor
    MyStrNoMove(const MyStrNoMove& str) : _len(str._len) {
        ++CCtor;
        _init_data(str._data);
    }
    // //=========== move ctor ================
    // MyStrNoMove(MyStrNoMove&& str) noexcept
    //     : _data(str._data), _len(str._len) {
    //     ++MCtor;
    //     str._len = 0;
    //     str._data = nullptr;//important
    // }
    // //======================================
    // copy-assign
    MyStrNoMove& operator=(const MyStrNoMove& str) {
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
    // //move-assign
    // MyStrNoMove& operator=(MyStrNoMove&& str) noexcept {
    //     ++MAsgn;
    //     // ----自我赋值检查-------------
    //     if (this != &str) {
    //         if (_data) delete _data;
    //         _len = str._len;//move
    //         _data = str._data; //move
    //         str._len = 0;
    //         str._data = nullptr;
    //     }
    //     //-----------------------
    //     return *this;
    // }
    // dtor
    virtual ~MyStrNoMove() {
        ++Dtor;
        if (_data) { delete _data; }
    }
    // reload compare operator
    bool operator<(const MyStrNoMove& rhs) const { // set
        return string(this->_data) < string(rhs._data);
    }
    bool operator==(const MyStrNoMove& rhs) const { // set
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
// ---------------------------------------
size_t MyStrNoMove::DCtor{}; // default ctor
size_t MyStrNoMove::Ctor{};  // ctor
size_t MyStrNoMove::CCtor{}; // copy-ctor
size_t MyStrNoMove::CAsgn{}; // copy-assign
size_t MyStrNoMove::MCtor{}; // move-ctor
size_t MyStrNoMove::MAsgn{}; // move-assign
size_t MyStrNoMove::Dtor{};  // dtor

// output func
template <typename T>
void output_static_data(const T& myStr) {
    cout << typeid(myStr).name() << " -- " << endl;
    cout << "CCtor=" << T::CCtor << " MCtor=" << T::MCtor
         << " CAsgn=" << T::CAsgn << " MAsgn=" << T::MAsgn
         << " Dtor=" << T::Dtor << " Ctor=" << T::Ctor << " DCtor=" << T::DCtor
         << endl;
}

template <typename M, typename NM>
void test_moveable(M c1, NM c2, long& value) {
    char buf[10];
    typedef typename iterator_traits<typename M::iterator>::value_type V1type;
    clock_t start = clock();

    for (long i = 0; i < value; i++) {
        snprintf(buf, 10, "%d", rand());
        auto ite = c1.end();
        c1.insert(ite, V1type(buf));
    }
    clock_t end1 = clock();
    cout << "construction, milli-seconds: "
         << 1000 * (end1 - start) / CLOCKS_PER_SEC << endl;
    cout << "size()=" << c1.size() << endl;
    output_static_data(*(c1.begin()));

    M c11(c1); // copy
    clock_t end2 = clock();
    cout << "copy, milli-seconds: " << 1000 * (end2 - end1) / CLOCKS_PER_SEC
         << endl;

    M c12(move(c1)); // move copy
    clock_t end3 = clock();
    cout << "move copy, milli-seconds: "
         << 1000 * (end3 - end2) / CLOCKS_PER_SEC << endl;

    c11.swap(c12);
    cout << "swap, milli-seconds: " << 1000 * (clock() - end3) / CLOCKS_PER_SEC
         << endl;
    // ============================================= //

    typedef typename iterator_traits<typename NM::iterator>::value_type V2type;
    clock_t start1 = clock();

    for (long i = 0; i < value; i++) {
        snprintf(buf, 10, "%d", rand());
        auto ite = c2.end();
        c2.insert(ite, V2type(buf));
    }
    clock_t end4 = clock();
    cout << "construction, milli-seconds: "
         << 1000 * (end4 - start1) / CLOCKS_PER_SEC << endl;
    cout << "size()=" << c2.size() << endl;
    output_static_data(*(c2.begin()));

    NM c21(c2); // copy
    clock_t end5 = clock();
    cout << "copy, milli-seconds: " << 1000 * (end5 - end4) / CLOCKS_PER_SEC
         << endl;

    NM c22(move(c2)); // move copy
    clock_t end6 = clock();
    cout << "move copy, milli-seconds: "
         << 1000 * (end6 - end5) / CLOCKS_PER_SEC << endl;

    c21.swap(c22);
    cout << "swap, milli-seconds: " << 1000 * (clock() - end6) / CLOCKS_PER_SEC
         << endl;
}


void t1() {
    long value = 3000000L;
    test_moveable(vector<MyString>(), vector<MyStrNoMove>(), value);
    // test_moveable(list<MyString>(), list<MyStrNoMove>(), value);
    // test_moveable(deque<MyString>(), deque<MyStrNoMove>(), value);
}

int main(int argc, char const* argv[]) {
    t1();
    // printf("%ld\n", CLOCKS_PER_SEC);//1000000
    return 0;
}