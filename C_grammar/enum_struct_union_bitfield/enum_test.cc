#include <stdio.h>

#include <typeinfo> //c++


void t1() {
    enum DAY12 { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
    DAY12 day;
    day = SUN;
    printf("%d, %s\n", day, typeid(DAY12).name());
    // 7, Z2t1vE5DAY12
}


void t2() {
    enum class week { mon = 1, tue, thu };
    week w1;
    w1 = week::mon;
    printf("mon=%d,w1=%d\n", week::mon, w1);
}


int main() {
    t1();
    // t2();
    return 0;
}
