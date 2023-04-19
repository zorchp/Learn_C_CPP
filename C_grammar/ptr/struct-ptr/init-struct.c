#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _person;
typedef struct _person {
    char* firstName; // 8
    char* lastName;
    char* title;
    unsigned int age; // 4
} Person;
struct _person1 {
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
} p2;
void t1() {
    Person p1; // with typedef
    printf("%lu\n", sizeof(p1));
    printf("%lu\n", sizeof(p2));
    printf("%lu\n", sizeof(struct _person1));
    // 32,内存对齐
}

void t2() {
    Person* ptrPerson;
    ptrPerson = (Person*)malloc(sizeof(Person));
    Person person;
    person.firstName = (char*)malloc(strlen("Emily") + 1);
    strcpy(person.firstName, "Emily");
    person.age = 23;
}

typedef struct _alternatePerson {
    char* firstName;
    char* lastName;
    char* title;
    short age;
} AlternatePerson;

void t3() {
    Person person;
    AlternatePerson otherPerson;
    printf("%lu\n", sizeof(Person));          // 32
    printf("%lu\n", sizeof(AlternatePerson)); // 32
    AlternatePerson people[30]; //内存有空隙, 取决于short的位置
}

int main(int argc, char const* argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}