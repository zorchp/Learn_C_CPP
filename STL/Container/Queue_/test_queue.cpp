#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void test1() {
    queue<int> que;
    que.push(5);
    que.push(6);
    que.push(7);
    que.push(8);
    cout << que.size() << endl;
    que.pop();
    int a = que.front(), b = que.back();
    cout << a << " " << b << endl;
    // cout<< que.size()<<endl;
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
