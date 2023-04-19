#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;
const int N = 3;

int main() {
    // int x[2][3] = {{1,2},{3,2,90},};
    // int x[][3] = {1,2,3,4,4,4,};
    double x[N][N];
    clock_t t0, t1;
    t0 = clock();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            x[i - 1][j - 1] = 1 / double(i + j - 1);
            cout << fixed << setprecision(3) << x[i - 1][j - 1] << "\t";
        }
        cout << endl;
    }
    t1 = clock();
    cout << "Time: " << double(t1 - t0) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}