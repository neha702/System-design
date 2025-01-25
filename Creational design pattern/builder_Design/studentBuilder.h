#ifndef STUDENTBUILDER_H
#define STUDENTBUILDER_H
#include "student.h"
using namespace std;

//Create the builder interface
class StudentBuilder {

public:
    int age;
    string name;
    vector<string>subjects;

   // setter functions
   // For every intermediate functions/step, we need to return builder
   StudentBuilder* setAge(int age) {
        this->age = age;
        return this;
   }

   StudentBuilder* setName(string name) {
        this->name = name;
        return this;
   }

   virtual StudentBuilder* setSubjects() = 0;

  // returns the final student
   Student* build() {
        return new Student(this);
   }

};

//Create Engineering student builder (only subjects would be different from MBA student builder)

class EngineeringStudentBuilder : public StudentBuilder {  
    public: 
        // only set subjects is overriden
        StudentBuilder* setSubjects() {
            vector<string>subjects;
            subjects.push_back("EMFT");
            subjects.push_back("analog");
            this->subjects = subjects;
            return this;
        }
};

//Create MBA student builder

class xMBAStudentBuilder : public StudentBuilder {
    public: 
        // only set subjects is overloaded
        StudentBuilder* setSubjects() {
            vector<string>subjects;
            subjects.push_back("economics");
            subjects.push_back("data interpretation");
            this -> subjects = subjects;
            return this;
        }
};
#endif 