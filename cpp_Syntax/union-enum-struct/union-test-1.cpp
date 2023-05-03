#include <iostream>
using namespace std;

union test {
    char mark;
    long num;
    float score;
};


int main(int argc, char const *argv[]) {
    int a = 1;
    cout << sizeof(test) << endl;
    return 0;
}