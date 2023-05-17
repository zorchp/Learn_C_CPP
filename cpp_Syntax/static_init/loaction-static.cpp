struct Test {
    int i;
    Test(int ii) : i(ii) {}
    Test() {}
};

Test t1 = Test(5);
Test t2;
static Test t3;
static Test t4{5};

int i = 1;
int j;
static int k;
static int l = 1;


int main() {
    //
    return 0;
}
