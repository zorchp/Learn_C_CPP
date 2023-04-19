#include <iostream>
#include <stack>
#include <string>


using namespace std;

void test01() {
    stack<int> st;
    int i = 0;
    while (i < 10) {
        st.push(i + 1);
        i++;
    }
    cout << "st的栈顶元素为: " << st.top() << endl;
    string s = "abcd";
    stack<char> mm;
    mm.push(s[0]);
    // char ss = s[0];
    cout << typeid(mm).name() << endl;
}

void t2() {
    //
    stack<int> st{{12}};
}

int main(int argc, char const* argv[]) {
    // test01();
    t2();
    return 0;
}
