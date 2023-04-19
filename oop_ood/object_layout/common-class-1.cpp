struct Base {
    Base() = default;
    ~Base() = default;

    void Func() {}

    int a;
    int b;
};

int main() {
    Base a;
    return 0;
}
