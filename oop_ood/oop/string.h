#ifndef __MYSTRING__
#define __MYSTRING__

class String {
public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator=(const String& str);
    ~String();
    char* get_c_str() const { return m_data; }

private:
    char* m_data;
    void create(const char* str);
};

#include <cstring>
#include <iostream>
using namespace std;

inline void String::create(const char* str) {
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str);
}

inline String::String(const char* cstr) {
    if (cstr) {
        create(cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String() {
    cout << "dtor" << endl;
    delete[] m_data;
}

inline String& String::operator=(const String& str) {
    if (this == &str) return *this;

    delete[] m_data;
    create(str.m_data);
    return *this;
}

inline String::String(const String& str) { create(str.m_data); }


ostream& operator<<(ostream& os, const String& str) {
    os << str.get_c_str();
    return os;
}

#endif
