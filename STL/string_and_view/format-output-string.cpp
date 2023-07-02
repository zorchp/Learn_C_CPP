#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

void t1() {
    double a = 3.14;
    double b = 1000.;
    cout.precision(2);
    cout << fixed << a << endl;
    cout << fixed << b << endl;
}

void t11() {
    double a = 3.14;
    double b = 1000.;
    cout << fixed << setprecision(2) << a << endl;
    cout << fixed << setprecision(2) << b << endl;
}
void t12() {
    // only setprecision, 输出数字的位数
    double s = 20.7843000;
    {
        cout << setprecision(1) << s
             << endl; // 输出2e+001，因为要输出一个数字，所以只有2
        cout << setprecision(2) << s << endl; // 输出21
        cout << setprecision(3) << s << endl; // 输出20.8
        cout << setprecision(6) << s << endl; // 输出20.7843
        cout << setprecision(7) << s << endl; // 输出20.7843
        cout << setprecision(8) << s << endl; // 输出20.7843
        cout << 1.00182001 << endl;
    }
    cout << 1.00182001 << endl;
    /* 2e+01 */
    /* 21 */
    /* 20.8 */
    /* 20.7843 */
    /* 20.7843 */
    /* 20.7843 */
    /* 1.001 */
}

void t13() {
    //
    double s = 20.7843000;
    cout.setf(ios::showpoint);

    cout << setprecision(1) << s
         << endl; // 输出2.e+001，注意，2和e之间多了一个“.”
    cout << setprecision(2) << s << endl; // 输出21.    多个点
    cout << setprecision(3) << s << endl; // 输出20.8
    cout << setprecision(6) << s << endl; // 输出20.7843
    cout << setprecision(7) << s << endl; // 输出20.78430
    cout << setprecision(8) << s << endl; // 输出20.784300
}

void t2() {
    double a = 30;
    double b = 10000.0;
    double pi = 3.1416;
    std::cout.precision(5);
    std::cout << std::showpoint << a << '\t' << b << '\t' << pi << '\n';
    std::cout << std::noshowpoint << a << '\t' << b << '\t' << pi << '\n';
    /* 30.000  10000.  3.1416 */
    /* 30      10000   3.1416 */
}

void t3() {
    /* basic_ostringstream<char> oss; */
    ostringstream oss;
    // 默认是right
    oss << setfill('0') << setw(5) << left << 123;
    cout << oss.str() << endl;
    cout << oss.str().insert(3, "-").insert(5, "-") << endl;
    /* 12300 */
    /* 123-0-0 */
}
void t4() {
    // 默认是right
    cout << setfill('0') << setw(5) << left << 123 << endl;
    /* 12300 */
}

void t5() {
    cout << setprecision(3) << 3.14159 << endl; // 3.14

    cout << fixed << setprecision(3) << 3.14159 << endl; // 3.142
}
int main(int argc, char *argv[]) {
    /* t1(); */
    /* t11(); */
    /* t12(); */
    /* t13(); */
    /* t2(); */
    /* t3(); */
    /* t4(); */
    t5();

    return 0;
}
