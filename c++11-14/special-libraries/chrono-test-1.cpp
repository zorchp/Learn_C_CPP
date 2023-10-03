#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;


void t1() {
    cout << "millisecond : ";
    cout << chrono::milliseconds::period::num << "/"
         << chrono::milliseconds::period::den << "s" << endl;
    /*millisecond : 1/1000s*/
}
void t2() {
    chrono::milliseconds mscond(1000); // 1 second
    cout << mscond.count() << " milliseconds.\n";

    cout << mscond.count() * chrono::milliseconds::period::num /
                chrono::milliseconds::period::den;
    cout << " seconds.\n";
    /*1000 milliseconds.
1 seconds.*/
}


void t3() {

    auto start = chrono::system_clock::now();
    // do something...
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "花费了"
         << (duration.count()) * chrono::microseconds::period::num /
                chrono::microseconds::period::den
         << "秒" << endl;
}
int main() {
    // t1();
    // t2();
    t3();

    return 0;
}