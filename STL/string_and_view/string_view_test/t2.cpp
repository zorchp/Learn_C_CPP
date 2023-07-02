#include <string_view>
#include <iostream>
using namespace std;

string ts;

void t1() {
    string_view s = "1,2,3";
    auto tmp = s.substr(0, 3);
    ts = tmp;
}

int main(int argc, char *argv[]) {
    t1();
    cout << ts << endl;
    return 0;
}
