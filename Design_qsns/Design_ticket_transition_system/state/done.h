#ifndef DONE_H
#define DONE_H
#include "../jiraUser.h"
#include "jiraState.h"
#include<iostream>
using namespace std;

class JiraTicket;

class Done : public JiraState{
public:
bool startAnalysing(JiraTicket* ticket , JiraUser* createdBy) {
    cout << "Moving Back to analysing state from done state" << endl;
    return true;
}
bool startReviewing(JiraTicket* ticket , JiraUser* createdBy) {
    cout << "Moving Back to review state from done state" << endl;
    return true;
}

bool markDone(JiraTicket* ticket , JiraUser* createdBy) {
    cout << "Already in done state" << endl;
    return false;
}
};
#endif