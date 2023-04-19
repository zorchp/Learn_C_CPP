#include <iostream>
using namespace std;

double i = 3.1415;
namespace XY {
bool i = false;
void f() {
    int i = 926;
    cout << i << endl;
}

} // namespace XY
int main(int argc, char *argv[]) {
    XY::f();
    return 0;
}
