#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class String {
    char* data_;

public:
    String() : data_(new char[1]) { *data_ = '\0'; }

    String(const char* str) : data_(new char[strlen(str) + 1]) {
        strcpy(data_, str);
    }

    // copy-ctor

    // String(const String& rhs) : data_(new char[rhs.size() + 1]) {
    //     strcpy(data_, rhs.c_str());
    // }

    String(const String& rhs) : String(rhs.data_) {} // C++11 delegation Ctor

    // copy assignment
    // 传统的实现
    // String& operator=(const String& rhs) {
    //     String tmp(rhs);
    //     swap(tmp);
    //     return *this;
    // }

    // copy and swap E11, E29
    String& operator=(String rhs) { // pass by value, 可以提供强烈的安全性保证
        // 为要修改的部分生成一份副本, 在副本上修改后交换
        // 若有任何修改动作抛出异常, 原件仍保持未改变状态
        // 待所有更改都成功后, 再将修改过的副本和原对象在一个 nothrow 的 swap
        // 中完成交换
        swap(rhs);
        return *this;
    }

    ~String() { delete[] data_; }

    // Accessors
    size_t size() const { return strlen(data_); }

    const char* c_str() const { return data_; }

    void swap(String& rhs) { // E25
        using std::swap;     // 可能也会用到全局的自定义 swap()
        swap(data_, rhs.data_);
    }
};

ostream& operator<<(ostream& os, const String& s) {
    os << s.c_str();
    return os;
}


void foo(String x) { cout << x << endl; }
void bar(const String& x) { cout << x << endl; }
String baz() {
    String ret("world");
    return ret;
}
int main() {
    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    s2 = s1;
    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s4 = baz();

    cout << "vector<String> test\n";
    std::vector<String> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(baz());
    svec.push_back("good job");
    for (auto i : svec) cout << i << endl;
}
