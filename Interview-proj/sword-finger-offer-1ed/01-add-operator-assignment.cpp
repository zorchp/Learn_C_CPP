class MyString {
public:
    MyString(char* pData = NULL);
    MyString(const MyString& str);
    MyString& operator=(const MyString& rhs);
    ~MyString();

private:
    char* m_pData;
    // 注意这里是指针, 所以需要动态内存分配和释放
    // 并且是c-style 字符串, 所以需要考虑c库函数, 不能直接赋值(strcpy)
};

/*
// 中规中矩, 未考虑代码的异常安全性, 因为new可能失败,
// 这样就导致原来的实例变动造成影响.
MyString& MyString::operator=(const MyString& rhs) {
    if (&rhs == this) return *this;
    delete[] m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(rhs.m_pData) + 1]; // 会引发内存不足
    strcpy(m_pData, rhs.m_pData);

    return *this;
}
*/

MyString& MyString::operator=(const MyString& rhs) {
    if (&rhs != this) { // 动态内存分配放在ctor中
        MyString tmp(rhs);
        // swap(tmp.m_pData, m_pData);
        char* pTmp=tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData=pTmp;
    }
    return *this;
}
