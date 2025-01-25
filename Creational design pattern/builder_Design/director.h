
#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "studentBuilder.h"
using namespace std;

//director  => responsible for building mba and engineering students  and  call methods in order
class Director {

private:
    Student* student;
    StudentBuilder* studentBuilder;

public: 
    Director(StudentBuilder* builder) {
        this->studentBuilder = builder;
    }

    //Based on student type create mba or engineering student
    Student* createStudent() {
        return studentBuilder->setAge(25)->setName("Neha")->setSubjects()->build();
    }

};
#endif 