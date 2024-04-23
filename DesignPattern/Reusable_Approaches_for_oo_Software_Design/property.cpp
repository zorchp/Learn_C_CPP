class Person {
    int age_;

public:
    int get_age() const { return age_; }

    void set_age(int value) { age_ = value; }

    // -fdeclspec
    __declspec(property(get = get_age, put = set_age)) int age;
};

int main(int argc, char *argv[]) {
    Person p;
    p.age = 20; // calls p.set_age(20)
    return 0;
}
