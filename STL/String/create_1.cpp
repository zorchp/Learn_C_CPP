#include <string>
#include <iostream>
using namespace std;

void t1() {
    string s1 = "";
    string s2 = "abc123";
    cout << "s2=" << s2 << endl;
    cout << "s2.size()=" << s2.size() << endl;
    cout << "s2.capacity()=" << s2.capacity() << endl;
    string(s2).swap(s2);
    cout << "s2=" << s2 << endl;
    cout << "s2.size()=" << s2.size() << endl;
    cout << "s2.capacity()=" << s2.capacity() << endl;
    cout << "s2.max_size()=" << s2.max_size() << endl;
}

void t2() {
    /* string a1 = u"and"; */
    //
}

int main(int argc, char const *argv[]) {
    /* t1(); */
    t2();
    return 0;
}
