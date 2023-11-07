#include <iostream>
#include <format>
using namespace std;

int g_i;
void f() {
    int f_i;

    cout << format("i in f() is {}\n", f_i);
}
int main() {
    int m_i;
#ifdef __clang__
    cout << "clang++\n";
    cout << format("i in main is {}\n", m_i);
    cout << format("i in global is {}\n", g_i);
    f();
#elif defined(__GNUC__) && !defined(__clang__)
    cout << "g++\n";
    cout << format("i in main is {}\n", m_i);
    cout << format("i in global is {}\n", g_i);
    f();
#endif
}
/*
clang++
i in main is 11095568
i in global is 0
i in f() is 131072

g++
i in main is 0
i in global is 0
i in f() is 1
*/
