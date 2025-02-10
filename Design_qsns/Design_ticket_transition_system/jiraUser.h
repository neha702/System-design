#ifndef JIRAUSER_H
#define JIRAUSER_H
#include <string>
using namespace std;

class JiraUser{
string name;
public:
JiraUser(string name) {
    this->name = name;
}
};
#endif