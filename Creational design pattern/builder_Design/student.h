#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class StudentBuilder;

class Student {

private:
    int age;
    string name;
    vector<string>subjects;

public:

   //constructor
   Student(StudentBuilder* builder) ;

   string toString () {
        return  "age: " + to_string(age) + " name: " + name + " subjects: " + subjects[0] + " " + subjects[1] ;
   }

};
#endif 