#include "../../bitsStd.h"
#include "director.h"
#include "studentBuilder.h"

//Instead of a class with long list of parameters , we can create this complex structure steps by steps at each step builder instance is returned
//at the end of build function it gives us the final product
using namespace std;

Student::Student(StudentBuilder* builder) {
    this->age = builder->age;
    this->name = builder->name;
    this->subjects = builder->subjects;
}

int main() {

StudentBuilder* mbaStudentBuilder =  new MBAStudentBuilder();
StudentBuilder* engineeringStudentBuilder =  new EngineeringStudentBuilder();

Director *director1 = new Director (mbaStudentBuilder);
Director *director2 = new Director (engineeringStudentBuilder);

Student* student1 = director1->createStudent();
Student* student2 = director2->createStudent();

cout << student1->toString() << endl;
cout << student2->toString() << endl;

return 0;
 
}

