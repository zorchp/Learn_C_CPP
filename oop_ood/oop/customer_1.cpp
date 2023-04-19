#include <iostream>
using namespace std;


class Customer {
public:
    Customer(string fn, string ln, long nu_) : fname(fn), lname(ln), nu(nu_) {}
    ~Customer() {}
    string getfn() const { return fname; }
    string getln() const { return lname; }
    long getnu() const { return nu; }

private:
    string fname;
    string lname;
    long nu;
};

bool operator==(const Customer& c1, const Customer& c2) {
    return (c1.getfn() == c2.getfn() && c1.getln() == c2.getln() &&
            c1.getnu() == c2.getnu());
}

void t1() {}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}