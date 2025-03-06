#ifndef COMMENT_H
#define COMMENT_H
#include <string>
#include "user.h"
using namespace std;

class User;

class Comment {
User* author;
string comment;
public:
Comment(User* author , string comment) {
    this->author = author;
    this->comment = comment;
}
};

#endif // COMMENT_H