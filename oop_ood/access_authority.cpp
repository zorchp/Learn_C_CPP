#include <iostream>

using namespace std;

class Person {
public:
    // 公共权限
    string myName;

    void func() {
        myName   = "zhangsan";
        myCar    = "bentian";
        Password = 465;
    }

protected:
    // 保护权限
    string myCar;

private:
    // 私有权限
    int Password;
};


int main(int argc, char const *argv[]) {
    /* code */
    Person p;
    p.myName = "lisi";
    // p.myCar="nnn";
    // p.Password=11111

    return 0;
}