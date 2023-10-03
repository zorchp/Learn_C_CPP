#include <armadillo>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <concepts>

using namespace std;

#define TEST_CONCEPT(Concept, Type) \
    cout << #Concept << '<' << #Type << ">: " << Concept<Type> << endl

#define TEST_CONCEPT2(Concept, Type1, Type2)            \
    cout << #Concept << '<' << #Type1 << ", " << #Type2 \
         << ">:" << Concept<Type1, Type2> << endl

int main(int argc, char *argv[]) {
    cout << boolalpha;
    cout << "__cpp_concepts is " << __cpp_concepts << endl;
    TEST_CONCEPT(regular, int);
    TEST_CONCEPT(regular, char);
    TEST_CONCEPT(integral, int);
    TEST_CONCEPT(integral, char);
    // TEST_CONCEPT(readable, int);
    // TEST_CONCEPT(readable, unique_ptr<int>);
    // TEST_CONCEPT2(writable, unique_ptr<int>, int);
    // TEST_CONCEPT2(writable, unique_ptr<int>, double);
    // TEST_CONCEPT2(writable, unique_ptr<int>, int *);
    TEST_CONCEPT(semiregular, unique_ptr<int>);
    TEST_CONCEPT(semiregular, shared_ptr<int>);
    TEST_CONCEPT(equality_comparable, unique_ptr<int>);
    TEST_CONCEPT(semiregular, arma::imat);
    TEST_CONCEPT2(assignable_from, arma::imat &, arma::imat &);
    TEST_CONCEPT(semiregular, arma::imat22);
    TEST_CONCEPT2(assignable_from, arma::imat22 &, arma::imat22 &);
    return 0;
}
