#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Singleton {
private:
    // C++构造函数并不是线程安全的
    // 延迟加载: lazy eval
    Singleton() { // 懒汉式, 仅懒汉式存在线程同步问题
        // 在需要时候才创建
        m_single = nullptr;
        cout << "Singleton creating...\n";
    }
    static Singleton* m_single;
    static mutex m;
    class Release {
    public:
        ~Release() {
            if (m_single != nullptr) {
                delete m_single;
                cout << "deleting Singleton...\n";
            }
        }
    };
    static Release m_MemRelease;

public:
    // static Singleton* getInstance() {
    //     if (m_single == nullptr) {
    //         // 双检查锁
    //         lock_guard<mutex> lock(m);
    //         if (m_single == nullptr) m_single = new Singleton;
    //     }
    //     return m_single;
    // }

    static Singleton* getInstance() {
        // C++11 , 最简洁
        static once_flag of;
        call_once(of, [&] { m_single = new Singleton; });
        return m_single;
    }
};
Singleton* Singleton::m_single{};
// 饿汉式, 不存在线程安全问题
//  Singleton* Singleton::m_single = new Singleton;
mutex Singleton::m;
Singleton::Release Singleton::m_MemRelease;

void t1() {
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    cout << hex << p1 << endl;
    cout << hex << p2 << endl;
    // Singleton creating...
    // 0x103500710
    // 0x103500710
}

void test_fun() { cout << hex << Singleton::getInstance() << endl; }
#define GET_NAME(x) t##x
void t2() {
    thread t1(test_fun);
    thread t2(test_fun);
    thread t3(test_fun);
    thread t4(test_fun);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    // 并不是线程安全的
    // Singleton creating...
    // 0x107400f70
    // Singleton creating...
    // 0x1074026b0
    // Singleton creating...
    // 0x107401ef0
    // Singleton creating...
    // 0x107401730
}

int main(int argc, char* argv[]) {
    // Singleton* s = new Singleton;
    // t1();
    t2();
    return 0;
}
