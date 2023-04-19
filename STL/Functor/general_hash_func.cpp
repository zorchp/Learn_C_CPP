#include <functional> //hash
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template <typename T>
inline void hash_combine(size_t& seed, const T& val) {
    seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T>
inline void hash_val(size_t& seed, const T& val) {
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types&... args) {
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

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

class CustomerHash_Naive {
public:
    size_t operator()(const Customer& c) const {
        cout << "hash<string>()(c.fname)=" << hash<string>()(c.getfn()) << endl;
        cout << "hash<string>()(c.lname)=" << hash<string>()(c.getln()) << endl;
        cout << "hash<long>()(c.nu)=" << hash<long>()(c.getnu()) << endl;
        size_t hash_code = hash<string>()(c.getfn()) +
                           hash<string>()(c.getln()) + hash<long>()(c.getnu());
        cout << "hash_code=" << hash_code << endl;
        return hash_code;
    }
};


void tt() {
    unordered_set<Customer, CustomerHash_Naive> custset;
    Customer c1("tom", "Mick", 10);
    custset.insert(c1);
    /*
hash<string>()(c.fname)=9063113526560649640
hash<string>()(c.lname)=7967037659428361427
hash<long>()(c.nu)=10
hash_code=17030151185989011077
    */
}


class CustomerHash {
public:
    size_t operator()(const Customer& c) const {
        size_t hash_code = hash_val(c.getfn(), c.getln(), c.getnu());
        cout << "hash_code=" << hash_code << endl;
        return hash_code;
    }
};

void t1() {
    unordered_set<Customer, CustomerHash> custset;
    Customer c1("tom", "Mick", 10);
    custset.insert(c1);
    cout << "custset.bucket_count()=" << custset.bucket_count() << endl;
    /*hash_code=4147245632987158385*/
}


size_t customer_hash_func(const Customer& c) {
    size_t hash_code = hash_val(c.getfn(), c.getln(), c.getnu());
    cout << "hash_code=" << hash_code << endl;
    return hash_code;
}

void t2() {
    unordered_set<Customer, size_t (*)(const Customer&)> custset(
        20, customer_hash_func); // bucket_count:20
    Customer c1("tom", "Mick", 10);
    custset.insert(c1);
    cout << "custset.bucket_count()=" << custset.bucket_count() << endl;
    /*
    hash_code=4147245632987158385
    custset.bucket_count()=23
    */
}

void t3() {
    // 使用struct hash的偏特化形式 实现hash function
}

int main(int argc, char const* argv[]) {
    // tt();  // naive
    t1();
    t2();
    return 0;
}