#include <bits/stdc++.h>

class EagerSingleton {
public:
    static EagerSingleton *getInstance() { return instance; }
    static void delInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }

private:
    EagerSingleton() { std::cout << "EagerSingleton Hello" << std::endl; };
    ~EagerSingleton() { // 私有化 可以避免 直接 delete s1 ，必须 使用
                        // delInstance
        std::cout << "EagerSingleton Bye" << std::endl;
    }
    // static对象，可以保证对象只生成一次,并且是多线程安全
    static EagerSingleton *instance;
};
// 饿汉模式的关键：初始化即实例化
EagerSingleton *EagerSingleton::instance = new EagerSingleton();

int main() {
    EagerSingleton *s1 = EagerSingleton::getInstance();
    EagerSingleton *s2 = EagerSingleton::getInstance();

    std::cout << "s1 address = " << s1 << std::endl;
    std::cout << "s2 address = " << s2 << std::endl;

    EagerSingleton::delInstance();
    /*EagerSingleton Hello
    s1 address = 0x6000013b8030
    s2 address = 0x6000013b8030
    EagerSingleton Bye*/
    return 0;
}
