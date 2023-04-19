#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
int main() {
    //定义毫秒级别的时钟类型
    typedef chrono::time_point<chrono::system_clock, chrono::milliseconds>
        microClock_type;
    //获取当前时间点，windows
    // system_clock是100纳秒级别的(不同系统不一样，自己按照介绍的方法测试)，所以要转换
    microClock_type tp = chrono::time_point_cast<chrono::milliseconds>(
        chrono::system_clock::now());
    //转换为ctime.用于打印显示时间
    time_t tt = chrono::system_clock::to_time_t(tp);
    char _time[50];
    struct tm* tm1 = localtime(&tt);
    strftime(_time, sizeof(_time), "%A %c", tm1);
    cout << "now time is : " << _time;
    //计算距离1970-1-1,00:00的时间长度，因为当前时间点定义的精度为毫秒，所以输出的是毫秒
    cout << "to 1970-1-1,00:00  " << tp.time_since_epoch().count() << "ms"
         << endl;
    return 0;
    /*now time is : Thursday Thu Oct  6 00:03:05 2022to 1970-1-1,00:00  1664985785666ms*/
}