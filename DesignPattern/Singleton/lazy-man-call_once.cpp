#include <bits/stdc++.h>

// by using mutex lock
class LazySingleton {
public:
    static LazySingleton *getInstance1() { // 调用时才实例化
        if (instance == nullptr) { // 第一次访问, 加锁, 保证不重复加锁
            std::lock_guard<std::mutex> lck(mtx);
            if (instance == nullptr) {
                // 实际的申请内存操作, 但是由于new不是atomic的,
                // 包含内存分配和调用ctor两个操作, 所以需要内存栅栏技术
                instance = new LazySingleton;
            }
        }
        return instance;
    }
    static LazySingleton *getInstance() { // 调用时才实例化
        static std::once_flag oc; // 用于call_once的局部静态变量
        std::call_once(oc, [&] { instance = new LazySingleton(); });
        return instance;
    }

    static void delInstance() { // 调用时才实例化
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }


private:
    LazySingleton() { std::cout << "LazySingleton Hello" << std::endl; };
    ~LazySingleton() { // 私有化 可以避免用户直接 delete s1
        std::cout << "LazySingleton Bye" << std::endl;
    }
    static LazySingleton *instance;
    static std::mutex mtx;
};

LazySingleton *LazySingleton::instance = nullptr;
std::mutex LazySingleton::mtx; // 声明锁


int main() {
    LazySingleton *s1 = LazySingleton::getInstance();
    LazySingleton *s2 = LazySingleton::getInstance();

    std::cout << "s1 address = " << s1 << std::endl;
    std::cout << "s2 address = " << s2 << std::endl;
    LazySingleton::delInstance(); // 必须自己释放
    /*LazySingleton Hello
    s1 address = 0x102ed4000
    s2 address = 0x102ed4000
    LazySingleton Bye*/
    return 0;
}
