#include <string>
using namespace std;
struct C {
    C(int i) : c(i){};
    int c;
};
struct init {
    int a = 1;
    string b{"hello"}; // 无法通过编译
    /* string b("hello"); // 无法通过编译 */
    /* C c(1);            // 无法通过编译 */
};
// 编译选项:g++ -std=c++11-c 2-7-2.cpjjkp
