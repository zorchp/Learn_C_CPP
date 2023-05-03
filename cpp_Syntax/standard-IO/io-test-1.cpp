#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    double x, y;
    cout << "first one:\n";
    if (!(cin >> x)) {
        cerr << "read error\n";
        return EXIT_FAILURE;
    }
    cout << "second one:\n";
    if (!(cin >> y)) {
        cerr << "read error\n";
        return EXIT_FAILURE;
    }
    cout << x << "X" << y << "=" << x * y << endl;
    return 0;
}
