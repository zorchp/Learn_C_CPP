#include <iostream>
#include <deque>
#include <stack>

using namespace std;


int main(int argc, char *argv[]) {
    deque<int> myDeque(3, 100);
    stack<int> myStack;
    stack<int> myStack2(myDeque);
    cout << "myStack size: " << myStack.size() << endl;
    cout << "myStack2 size: " << myStack2.size() << endl;
    myStack2.pop();
    cout << "myStack2 size: " << myStack2.size() << endl;
    cout << "myStack2 top: " << myStack2.top() << endl;
    return 0;
}
