#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
string name;
int age;

public:
Person(string name, int age) {
    this->name = name;
    this->age = age;
}

string getName() {
    return name;
}
};

#endif // PERSON_H