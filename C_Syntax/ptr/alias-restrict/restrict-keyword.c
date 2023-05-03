#include <stdio.h>

void add(int size, double *restrict arr1, const double *restrict arr2) {
    for (int i = 0; i < size; i++) { arr1[i] += arr2[i]; }
}
void print(double *vec, int size) {
    for (int i = 0; i < size; i++) printf("%f, ", vec[i]);
    putchar('\n');
}

void t1() { // right
    double vector1[] = {1.1, 2.2, 3.3, 4.4};
    double vector2[] = {1.1, 2.2, 3.3, 4.4};
    add(4, vector1, vector2);
    print(vector1, 4);
    print(vector2, 4);
    /*
    2.200000, 4.400000, 6.600000, 8.800000,
    1.100000, 2.200000, 3.300000, 4.400000,
    */
}

void t2() { // wrong, use the same ptr to two vec
    double vector1[] = {1.1, 2.2, 3.3, 4.4};
    double *vector3  = vector1;
    add(4, vector1, vector3);
    add(4, vector1, vector1);
    print(vector1, 4);
    print(vector3, 4);
    /*
    4.400000, 8.800000, 13.200000, 17.600000,
    4.400000, 8.800000, 13.200000, 17.600000,
    */
}

int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}