#include <iostream>
#include <vector>

using namespace std;

void test1() {
    // 容器嵌套容器
    vector<vector<int>> v;

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    // 小容器中添加数据
    for (int i = 0; i < 3; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
    }

    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 通过大容器遍历所有的数据
    for (vector<vector<int>>::iterator it = v.begin(); it < v.end(); it++) {
        for (vector<int>::iterator vit = (*it).begin(); vit < (*it).end();
             vit++) {
            // (*it) 对应容器vector<int>
            cout << *vit << " ";
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[]) {
    test1();
    return 0;
}