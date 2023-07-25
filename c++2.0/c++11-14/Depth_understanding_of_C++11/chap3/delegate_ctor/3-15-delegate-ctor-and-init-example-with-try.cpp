#include <iostream>
using namespace std;
class DCExcept {
public:
    // 委派构造函数中使用try, 可以捕获到目标构造中抛出的异常
    DCExcept(double d) try : DCExcept(1, d) {
        // 此处并没有执行
        cout << "Run the body." << endl;
        // 其他初始化
    } catch (...) {
        cout << "caught exception." << endl;
    }

private:
    // 目标构造函数中throw
    DCExcept(int i, double d) {
        cout << "going to throw!" << endl;
        throw 0;
    }
    int type;
    double data;
};
int main() { DCExcept a(1.2); }
/* going to throw! */
/* caught exception. */
/* libc++abi: terminating with uncaught exception of type int */
