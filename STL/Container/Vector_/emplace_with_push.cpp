#include <__utility/integer_sequence.h>
#include <vector>

using namespace std;

struct Blob {};
void t1() {
    vector<Blob> blobs;
    Blob b{};
    blobs.emplace_back(b);
    blobs.push_back(b);
}

void t2() {
    vector<bool> vb;
    vb.push_back(1);
    vb.emplace_back(1);
}
int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
