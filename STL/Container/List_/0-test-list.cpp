#include <list>
// #include <forward_list>
// #include <array>
// #include <cstdlib>
// #include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    list<int> lst{1};
    lst.push_back(12);
    cout << lst.size() << endl;
    if (lst.size() != 0) cout << "true" << endl;
    cout << lst.size() << endl;
    cout << sizeof(list<string>) << endl; // 24, 3指针
    return 0;
}
/*
2
true
2
*/
