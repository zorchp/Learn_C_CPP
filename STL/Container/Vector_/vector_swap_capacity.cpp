#include <iostream>
#include <vector>

using namespace std;


void t1() {
    // 尾插法插入元素
    vector<int> v;
    for (int i = 0; i < 10000; i++) { v.push_back(i * 2 + 1); }

    // 在内存分配过大时采用swap()函数可以回收被过多分配的空间
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.resize(3);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    // 此时使用swap()回收内存
    vector<int>(v).swap(v);

    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}