#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;


int main(int argc, char const* argv[]) {
    //距离时间戳2两秒
    chrono::time_point<chrono::system_clock, chrono::seconds> tp(
        chrono::seconds(2));
    cout << "to epoch : " << tp.time_since_epoch().count() << "s" << endl;
    //转化为ctime，打印输出时间点
    time_t tt = chrono::system_clock::to_time_t(tp);
    char buf[50];
    struct tm* tm1;
    tm1 = localtime(&tt);
    strftime(buf, sizeof(buf), "%A %c", tm1);

    cout << buf << endl;
    /*to epoch : 2s
Thursday Thu Jan  1 08:00:02 1970*/
    return 0;
}