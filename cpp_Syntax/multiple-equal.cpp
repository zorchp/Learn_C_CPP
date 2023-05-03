#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[]) {
    long ans = 1;
    for (int i = 0; i < 9; ++i) {
        /* ans = ans * (10 + i) / (i + 1); */
        ans *= (10 + i) / (i + 1);
        cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
/* 10 */
/* 55 */
/* 220 */
/* 715 */
/* 2002 */
/* 5005 */
/* 11440 */
/* 24310 */
/* 48620 */

10
50
200
600
1200
2400
4800
9600
19200

