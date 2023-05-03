#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <numeric>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <string>
#include <list>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>

void c_func() {
    char a[10];
    sprintf(a, "%d", 10);
    printf("%s\n", a);
    printf("%d\n", atoi("12"));
}
#ifdef __cplusplus
}
#endif


int main(int argc, char const* argv[]) {
    c_func();
    return 0;
}