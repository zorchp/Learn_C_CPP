#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 先定义一个Person类
class P {
public:
    string name;
    int age;

    P(string name, int age) {
        this->name = name;
        this->age  = age;
    }
};

void myprint(P &val) {
    cout << "name: " << val.name << "  age: " << val.age << endl;
}


// 存放自定义数据类型的值
void test1() {
    vector<P> v;
    P p1("a", 1);
    P p2("b", 3);
    P p3("c", 5);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // // 遍历方式1
    // vector<P>::iterator itBegin = v.begin();
    // vector<P>::iterator itEnd = v.end();
    // while(itBegin != itEnd)
    // {
    //     // cout<<"name: "<<(*itBegin).name<<" age:  "<<(*itBegin).age<<endl;
    //     cout<<"name: "<<itBegin->name<<" age:  "<<itBegin->age<<endl;
    //     itBegin++;
    // }

    // // 遍历方式2
    // for (vector<P>::iterator it = v.begin();it != v.end();it++)
    // {
    //     // cout<<"name: "<<(*it).name<<" age:  "<<(*it).age<<endl;
    //     cout<<"name: "<<it->name<<"  age: "<<it->age<<endl;
    // }

    // 遍历方式3
    for_each(v.begin(), v.end(), myprint);
}


void myprint1(P *&val) {
    cout << "name: " << (*val).age << "  age: " << (*val).name << endl;
}

// 存放自定义数据类型的指针
void test2() {
    vector<P *> v;
    P p1("a", 1);
    P p2("b", 3);
    P p3("c", 5);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    // // 遍历方式1
    // vector<P>::iterator itBegin = v.begin();
    // vector<P>::iterator itEnd = v.end();
    // while(itBegin != itEnd)
    // {
    //     // cout<<"name: "<<(*itBegin).name<<" age:  "<<(*itBegin).age<<endl;
    //     cout<<"name: "<<itBegin->name<<" age:  "<<itBegin->age<<endl;
    //     itBegin++;
    // }

    // // 遍历方式2
    // for (vector<P*>::iterator it = v.begin();it != v.end();it++)
    // {
    //     // 指针的指针
    //     cout<<"name: "<<(**it).name<<"  age: "<<(**it).age<<endl;
    //     // 外层指针解引用之后得到类的指针再取值
    //     cout<<"name: "<<(*it)->name<<"  age: "<<(*it)->age<<endl;
    // }

    // 遍历方式3
    for_each(v.begin(), v.end(), myprint1);
}

int main() {
    // test1();
    test2();
    return 0;
}
