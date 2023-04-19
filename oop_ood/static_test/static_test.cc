#include <iostream>
using namespace std;

/*

*/
class Account {
public:
    // 类内声明
    static double m_rate;
    static void set_rate(const double &x) { m_rate = x; }
};

// 类外定义
double Account::m_rate = 8.0;


int main(int argc, char const *argv[]) {
    cout << Account::m_rate << endl;
    Account::set_rate(5.09);
    cout << Account::m_rate << endl;
    Account a;
    a.set_rate(7.0);
    cout << Account::m_rate << endl;

    return 0;
}