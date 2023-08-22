#include <bits/stdc++.h>

// by using static variable
class LazySingleton {
public:
    static LazySingleton *getInstance() { // 调用时才实例化
        static LazySingleton instance;
        return &instance;
    }

private:
    LazySingleton() { std::cout << "LazySingleton Hello" << std::endl; };
    ~LazySingleton() { // 私有化 可以避免用户直接 delete s1
        std::cout << "LazySingleton Bye" << std::endl;
    }
};

int main() {
    LazySingleton *s1 = LazySingleton::getInstance();
    LazySingleton *s2 = LazySingleton::getInstance();

    std::cout << "s1 address = " << s1 << std::endl;
    std::cout << "s2 address = " << s2 << std::endl;

    /*LazySingleton Hello
    s1 address = 0x102ed4000
    s2 address = 0x102ed4000
    LazySingleton Bye*/
    return 0;
}
