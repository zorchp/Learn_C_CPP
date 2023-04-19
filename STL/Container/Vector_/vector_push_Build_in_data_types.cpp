#include <algorithm>
#include <iostream>
#include <vector>

// #include <string>

using namespace std;

void myprint(int val) { cout << val; }

void test1() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    // // 遍历方式1
    // vector<int>::iterator itBegin = v.begin();
    // vector<int>::iterator itEnd = v.end();
    // while(itBegin != itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    // }

    // // 遍历方式2
    // for (vector<int>::iterator it = v.begin();it< v.end();it++)
    // {
    //     cout<<*it<<endl;
    // }

    // 遍历方式3: 需要algorithm头文件, 以及自定义的函数
    for_each(v.begin(), v.end(), myprint);
}

int main() {
    test1();
    return 0;
}
