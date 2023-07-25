#include <ios>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <cassert>
using namespace std;
using namespace std::string_literals;

auto filename = "./test.txt"s;

void t1() {
    ofstream f;
    f.open(filename);
    f << filename << endl;
    f << filename << endl;
    f << filename << endl;
    f.close();

    std::ifstream iff;
    iff.open(filename);
    assert(iff.is_open());
    string ans, tmp;
    while (iff >> tmp) {
        ans += tmp + '\n';
    }
    cout << ans << endl;
    iff.close();
}


void t2() {
    fstream f(filename); // 可读可写
    // f << "123"; // 默认从头开始写入
    f.seekp(3); // 从 begin 移动了 3 个字节
    f << "123";
    // enum seekdir {beg, cur, end};
    f.seekp(3, ios::cur); // cur当前位置再移动 3 个字节
    f << "123";

    f.close();
}

void t3() {
    std::fstream s(filename, s.in | s.trunc | s.out);
    if (!s.is_open())
        std::cout << "failed to open " << filename << '\n';
    else {
        // write
        double d{3.14};
        s.write(reinterpret_cast<char *>(&d), sizeof d); // binary output
        s << 123 << "abc";                               // text output

        // for fstream, this moves the file position pointer (both put and get)
        s.seekp(0);

        // read
        d = 2.71828;
        s.read(reinterpret_cast<char *>(&d), sizeof d); // binary input
        int n;
        std::string str;
        if (s >> n >> str) // text input
            std::cout << "read back from file: " << d << ' ' << n << ' ' << str
                      << '\n';
    }
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
