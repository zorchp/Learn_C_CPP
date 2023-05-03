#include <cstdio>

enum DAY : long { //声明了类型为long, c++11
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

DAY operator++(DAY& day) {
    day = static_cast<DAY>(1 + static_cast<int>(day));
    return day;
}

void t1() {
    DAY day = MON;
    // printf("%d\n", day);//1
    // 遍历枚举元素, 连续可以遍历
    for (; day <= static_cast<int>(SUN); ++day)
        printf("枚举元素：%lu \n", day); //此时应该用lu or ld
    /*
    枚举元素：1
    枚举元素：2
    枚举元素：3
    枚举元素：4
    枚举元素：5
    枚举元素：6
    枚举元素：7
    */
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}