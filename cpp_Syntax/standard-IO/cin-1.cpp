#include <iostream>
#include <sstream>
using namespace std;

void t0() {
    std::string str = "Hello, world";
    std::istringstream in(str);
    std::string word;
    in >> word;
    std::cout << "After reading the word \"" << word << "\" tellg() returns "
              << in.tellg() << '\n';
}

void t1() {
    cin.putback('1');
    cout << cin.get() << endl;
    cin.unget();
    cout << cin.get() << endl;
    cout << "new\n";
    cout << cin.peek() << endl;
    cout << cin.get() << endl;
    // cout << format("tellg={}\n", (int)cin.tellg());
    // cout << "tellg = " << cin.tellg() << endl;
}

int main(int argc, char *argv[]) {
    // t0();
    t1();
    return 0;
}
