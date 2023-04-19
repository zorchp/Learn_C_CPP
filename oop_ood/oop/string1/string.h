#ifndef __MYSTRING__
#define __MYSTRING__

class String {
public:
    // 默认构造
    String(const char *cstr = 0);

    // 拷贝构造
    String(const String &str);

    // 拷贝赋值
    String &operator=(const String &str);

    // 析构
    ~String();

    // 成员函数
    char *get_c_str() const { return m_data; }

private:
    char *m_data;
};

#include <cstring>

inline String::String(const char *cstr) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        // 字符数组首地址为指针
        *m_data = '\0';
    }
}

inline String::~String() { delete[] m_data; }

inline String &String::operator=(const String &str) {
    if (this == &str) return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline String::String(const String &str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const String &str) {
    os << str.get_c_str();
    return os;
}

#endif // __MYSTRING__
