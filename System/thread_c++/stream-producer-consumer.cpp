#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_NUM = 100'000;
constexpr int THREAD_NUM = 100;


int main(int argc, char *argv[]) {
    //
    // 模拟长文本文件, 这里仅以数组形式给出
    vector<string> data(MAX_NUM);
    for (int i{}; i < MAX_NUM; ++i) {
        data[i] = to_string(i);
    }
    // 此时需要建立 100 个线程, 执行之后重回队列, 直到任务结束
    return 0;
}
