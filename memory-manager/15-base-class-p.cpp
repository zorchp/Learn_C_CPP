class P {
public:
    // P() = default;
    int a; // 4bytes
    virtual ~P() {}
};
int main(int argc, char *argv[]) {
    P p;
    return 0;
}
