#include <iostream>
#include <functional>
#include <unistd.h>
#include <vector>

using namespace std;

void t1() {
    int i{};
    cout << "func t1(), i=" << i << endl;
    function<void(void)> f = [&]() {
        cout << "func f(), i=" << i << endl;

        // if (i == 3) return;
        sleep(1);
        for (i = 0; i < 3; i++) {
            cout << "loop, i=" << i << endl;
            f();
        }
        return;
    };
    f();
}
ostream& operator<<(ostream& os, const vector<bool>& v) {
    for (auto i : v) os << i << " ";
    os << endl;
    return os;
}
void t2() {
    vector<bool> v(3, 1);
    cout << v;
    for (int i = 3; i < 100; i++) cout << "v[" << i << "]=" << v[i] << endl;
}

int main(int argc, char* argv[]) {
    // t1();
    t2();
    return 0;
}
