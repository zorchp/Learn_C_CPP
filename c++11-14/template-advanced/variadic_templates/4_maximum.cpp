#include <iostream>

using namespace std;

int maximum(int n) { return n; }


template <typename... Args>
int maximum(int n, Args... args) {
    return max(n, maximum(args...));
}


int main(int argc, char const *argv[]) {
    cout << maximum(1, 2, 3, 4, 45);
    return 0;
}