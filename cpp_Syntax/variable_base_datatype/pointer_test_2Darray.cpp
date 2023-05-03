#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a[][3] = {
        1, 2, 3, 4, 5,
    };
    int *pa = a[0];

    cout << a << endl;
    cout << a[0] << endl;
    cout << pa << endl;

    cout << setw(3) << a[1][1] << endl;
    return 0;
}