#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    ofstream ofs;
    ofs.open("~/code/test.txt", ios::binary);
    for (int i{}; i < 1000'000; ++i) {
        auto s = to_string(i) + "\n";
        ofs.write(s.c_str(), s.size());
    }
    ofs.close();
    return 0;
}
