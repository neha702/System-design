#ifndef USER_H
#define USER_H
#include <string>
#include "location.h"
using namespace std;

class User {
public:
string name;
string email;
Location* location;
User(string name , string email) {
    this->name = name;
    this->email = email;
}

string getUserName() {
    return name;
}
};

#endif // USER_H