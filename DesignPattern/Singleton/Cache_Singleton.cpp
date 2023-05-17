#include <iostream>
#include <map>
#include <string>

using namespace std;


class Singleton;
// 存键值对
static map<string, Singleton*> myMap{};


// 延迟加载

class Singleton {
private:
    Singleton() {
        m_single = nullptr;
        cout << "creating Singleton\n";
    }

public:
    static Singleton* getInstance() {
        if (myMap.find(DEFAULT_KEY) != myMap.end()) {
            return myMap[DEFAULT_KEY];
        }
        if (!m_single) {
            m_single = new Singleton;
            // 存入缓存
            myMap[DEFAULT_KEY] = m_single;
        }
        return m_single;
    }

private:
    static Singleton* m_single;
    static string DEFAULT_KEY;
};

Singleton* Singleton::m_single = nullptr;
string Singleton::DEFAULT_KEY = "One";

int main(int argc, char* argv[]) {
    auto p1 = Singleton::getInstance();
    auto p2 = Singleton::getInstance();
    cout << hex << p1 << endl;
    cout << hex << p2 << endl;
    // creating Singleton
    // 0x600003b84040
    // 0x600003b84040

    return 0;
}
