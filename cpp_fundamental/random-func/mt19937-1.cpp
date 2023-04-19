#include <iostream>
#include <random>
#include <functional>

using namespace std;


void t1() {
    random_device engine{}; // 硬件随机数
    mt19937 gen{engine()};
    uniform_real_distribution<double> dis;
    int k{3};
    while (k--) cout << dis(gen) << endl;
}

void t2() {
    std::default_random_engine generator; // 每次生成固定值
    // random_device generator; // 硬件随机数, 每次不一样
    std::uniform_int_distribution<int> distribution(1, 6);
    for (int i{}; i < 10; ++i) {
        int dice_roll =
            distribution(generator); // generates number in the range 1..6
        // cout << dice_roll << " ";
        // auto dice = std::bind(distribution, generator);
        // int wisdom = dice() + dice() + dice();
        // cout << wisdom << "   ";
    } // 1 1 5 3 4 2 1 5 5 6
    cout << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    // t2();
    return 0;
}