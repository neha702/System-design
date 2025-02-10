#ifndef TICKET_H
#define TICKET_H
using namespace std;
#include "jiraUser.h"
#include "state/jiraState.h"
#include "state/todo.h"
#include<string>

class JiraTicket {
JiraUser* createdBy;
string description;
JiraState* state;
public:
JiraTicket(JiraUser* createdBy , string description) {
    this->createdBy = createdBy;
    this->description = description;
    this->state = new Todo();
}

JiraState* getCurrentState() {
    return state;
}

void setJiraState(JiraState* state) {
    this->state = state;
}
};

#endif