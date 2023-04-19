#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;


void t1() {
    static vector<int> v{1, 2, 3};
    cout << v[1] << endl;
}

static vector<int> g_v;
auto a = {1, 2, 3};
void t2() {
    cout << g_v[0] << endl; //
}


int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}