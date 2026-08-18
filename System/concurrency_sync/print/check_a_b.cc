#include <bits/stdc++.h>

using namespace std;

int check_pattern(const char* file_name, int pattern_num) {
    ifstream ifs(file_name);
    if (!ifs) {
        cerr << "Cannot open file: " << file_name << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(ifs)),
                   istreambuf_iterator<char>());
    ifs.close();

    int count = 0;
    for (size_t i = 0; i + 1 < content.size(); i += 2) {
        if (content[i] == 'A' && content[i + 1] == 'B') {
            ++count;
        } else {
            cerr << "Invalid pattern at position " << i
                 << ": expected 'AB', got '" << content[i] << content[i + 1]
                 << "'" << endl;
            return 1;
        }
    }

    if (content.size() % 2 != 0) {
        cerr << "Invalid content length: odd number of characters ("
             << content.size() << ")" << endl;
        return 1;
    }

    if (count != pattern_num) {
        cerr << "Pattern count mismatch: expected " << pattern_num << ", got "
             << count << endl;
        return 1;
    }

    cout << "OK: " << count << " AB patterns found" << endl;
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file pattern_num\n", argv[0]);
        return 1;
    }
    return check_pattern(argv[1], atoi(argv[2]));
}