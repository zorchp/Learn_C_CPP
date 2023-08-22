#include <iostream>
#include <map>
#include <string>

using namespace std;

const static int NUM_MAX = 2;

class Singleton;
// 存键值对
static map<int, Singleton*> myMap{};


class Singleton {
private:
    Singleton() {
        m_single = nullptr;
        cout << "creating Singleton...\n";
    }

public:
    static Singleton* getInstance() {
        m_single = myMap[m_InstanceCount];
        if (!m_single) {
            m_single = new Singleton;
            // 存入缓存
            myMap[m_InstanceCount] = m_single;
        }
        ++m_InstanceCount;
        if (m_InstanceCount > NUM_MAX) m_InstanceCount = 1;
        return m_single;
    }

private:
    static Singleton* m_single;
    static int m_InstanceCount; // 存放实例的个数
};

Singleton* Singleton::m_single = nullptr;
int Singleton::m_InstanceCount{1};

int main(int argc, char* argv[]) {
    auto p1 = Singleton::getInstance();
    auto p2 = Singleton::getInstance();
    auto p3 = Singleton::getInstance();
    auto p4 = Singleton::getInstance();
    cout << hex << p1 << endl;
    cout << hex << p2 << endl;
    cout << hex << p3 << endl;
    cout << hex << p4 << endl;

    return 0;
}
