#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    // vector<string> v={"2mec", "dede"}
    vector<bool> v = {true, false};
    for (auto i : v) cout << i << ", ";
    cout << endl;
    return 0;
}
