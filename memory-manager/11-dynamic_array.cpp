#include <iostream>
#include <memory>

using namespace std;
void t1() {
    int* pia = new int[12];
    unique_ptr<int[]> up(new int[10]);
    up.release();
}
void t2() {
    // 如果使用共享指针, 则需要自定义删除器(lambda)
    shared_ptr<int> sp(new int[10], [](int* p) {
        delete[] p;
        cout << "call deletor...\n";
    });
    // 并且只能用`get()`访问数组元素
    for (size_t i = 0; i != 10; ++i) *(sp.get() + i) = i;
    sp.reset(); // 这会调用刚才写好的lambda删除器
    // call deletor...
}
int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
