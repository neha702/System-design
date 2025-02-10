#ifndef REVIEW_H
#define REVIEW_H
#include "../jiraUser.h"
#include "jiraState.h"
#include<iostream>
using namespace std;

class JiraTicket;

class Review : public JiraState{
public:
bool startAnalysing(JiraTicket* ticket , JiraUser* createdBy) override{
    cout << "Moving back to analysing state from review state" << endl;
    return true;
}
bool startReviewing(JiraTicket* ticket , JiraUser* createdBy) override{
    cout << "Already in review state" << endl;
    return false;
}

bool markDone(JiraTicket* ticket , JiraUser* createdBy) override{
    cout << "Move to done state from review state" << endl;
    return true;
}
};
#endif