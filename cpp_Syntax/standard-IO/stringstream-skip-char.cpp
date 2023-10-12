#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

void t1() {
    string s;
    cin >> s;
    stringstream ss(s);
    ss.get(); // skip '('
    string item;
    // method 1:
    // while (getline(ss, item, ',')) {
    //     cout << stoi(item) << " ";
    // }
    // // method 2:
    // custom sstream?
    cout << '\n';
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
