#ifndef STATE_H
#define STATE_H

class JiraTicket;
class JiraUser;


class JiraState{
public:
virtual bool startAnalysing(JiraTicket* ticket , JiraUser* createdBy) = 0;
virtual bool startReviewing(JiraTicket* ticket , JiraUser* createdBy) = 0;
virtual bool markDone(JiraTicket* ticket , JiraUser* createdBy) = 0;
};
#endif