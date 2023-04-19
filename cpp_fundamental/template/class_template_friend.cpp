#include <iostream>
#include <string>

using namespace std;

// 声明类模板
template <class T1, class T2>
class Person;

// 实现全局函数
template <class T1, class T2>
void printP2(Person<T1, T2> &p) {
    cout << "name: " << p.m_name << " age: " << p.m_age << endl;
}


template <class T1, class T2>
class Person {
    // // 全局函数的类内实现(友元)
    // friend void printP1(Person<T1, T2> &p)
    // {
    //     cout<<"name: "<<p.m_name<<" age: "<<p.m_age<<endl;
    // }

    // 类外实现: 这里需要加上空模板的参数列表
    friend void printP2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age) : m_name(name), m_age(age) {}

private:
    T1 m_name;
    T2 m_age;
};

void test1() {
    Person<string, int> p("abc", 10);
    printP2(p);
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}