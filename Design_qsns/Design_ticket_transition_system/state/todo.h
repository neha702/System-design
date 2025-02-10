#ifndef TODO_H
#define TODO_H

#include "../jiraUser.h"
#include "jiraState.h"
#include<iostream>
using namespace std;


class JiraTicket;

class Todo : public JiraState {
public:
    bool startAnalysing(JiraTicket* ticket, JiraUser* createdBy) {
        cout << "Already in todo state" << endl;
        return false;
    }

    bool startReviewing(JiraTicket* ticket, JiraUser* createdBy) {
        cout << "Moving to review state from todo state" << endl;
        return true;
    }

    bool markDone(JiraTicket* ticket, JiraUser* createdBy){
        cout << "Moving to done state from todo state" << endl;
        return true;
    }
};

#endif