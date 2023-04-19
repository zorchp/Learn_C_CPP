#include <iostream>
#include <iterator>
#include <list>
// #include <unistd.h>

using namespace std;


template <typename T>
void printc(list<T> &v) {
    for (typename list<T>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    list<int> foo;
    for (int i = 1; i <= 5; i++) { foo.push_back(i); }
    cout << "foo: " << endl;
    printc(foo);
    cout << "input number which is inserted:" << endl;
    // 初始化迭代器, 此时已经*开始*从键盘等待用户输入
    istream_iterator<int> iit(cin), eos; // char is eos(for int)

    copy(iit, eos, inserter(foo, foo.begin()));
    if (iit != eos) {
        // cout<<"insert "<<"\""<<*iit<<"\"..."<<endl;
        cout << "foo contains:" << endl;
        printc(foo);
    }

    return 0;
}