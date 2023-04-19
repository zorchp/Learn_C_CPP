#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;


int main() {
    std::string s = "This Is An Example";

    // cout << *std::find(s.begin(), s.end(), ' ') << endl;
    // cout << s.find(' ') << endl;

    std::cout << "1) " << s << '\n';

    s.erase(7, 3); // erases " An" using overload (1)
    std::cout << "2) " << s << '\n';

    s.erase( // std::find返回找到的第一个元素的迭代器(指向单一元素)
        std::find(s.begin(), s.end(), ' ')); // erases first ' '; overload (2)
    std::cout << "3) " << s << '\n';

    s.erase( // 成员函数find返回找到的第一个元素的下标(数值)
        s.find(' ')); // trims from ' ' to the end of the string; overload (1)
    std::cout << "4) " << s << '\n';

    auto it =
        std::next(s.begin(), s.find('s')); // obtains iterator to the first 's'
    s.erase(it, std::next(it, 2));         // erases "sI"; overload (3)
    std::cout << "5) " << s << '\n';
}
/*
1) This Is An Example
2) This Is Example
3) ThisIs Example
4) ThisIs
5) This
*/