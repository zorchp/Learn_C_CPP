#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int radius = 10;   // 圆的半径
    const int center_x = 10; // 圆心的x坐标
    const int center_y = 10; // 圆心的y坐标

    for (int y = 0; y < center_y + radius; y++) {
        for (int x = 0; x < center_x + radius; x++) {
            int distance_squared = pow(x - center_x, 2) + pow(y - center_y, 2);
            if (distance_squared <= pow(radius, 2)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
