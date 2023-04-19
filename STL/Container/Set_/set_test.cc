#include <iostream>
#include <set>
#include <unordered_set>


using namespace std;
int main() {
    set<int> s;

    // 插入元素的函数
    // 在set容器中
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(5);
    s.insert(30);

    cout << "集合中的元素是: ";
    // for (auto it = s.begin(); it != s.end(); it++)
    //     cout << *it << " ";
    for (auto &i : s) cout << i << " ";
    cout << endl;
    cout << "迭代器指向: " << *s.find(9) << endl;
    s.erase(4);
    for (auto &i : s) cout << i << " ";
    cout << endl;

    return 0;
}