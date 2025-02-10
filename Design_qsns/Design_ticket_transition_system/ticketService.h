#ifndef TICKETSERVICE_H
#define TICKETSERVICE_H
using namespace std;
#include <string>
#include "jiraTicket.h"
#include "ticketEnum.h"
#include "state/jiraState.h"
#include "state/done.h"
#include "state/review.h"
#include "state/todo.h"

class TicketService{
public:
static mutex mtx;
static TicketService* ticketServiceInstance;
static TicketService* getTicketServiceInstance() {
    if(ticketServiceInstance == nullptr) {
        mtx.lock();
        if(ticketServiceInstance == nullptr) {
            ticketServiceInstance = new TicketService();
        }
        mtx.unlock();
    }
    return ticketServiceInstance;
}

JiraTicket* createTicket(JiraUser* createdBy , string description) {
    return new JiraTicket(createdBy , description);
}

static void changeTicketState(JiraTicket* ticket , TicketState state , JiraUser* u) {
    JiraState* currentState = ticket->getCurrentState();
    JiraState* finalState = nullptr;
    bool doable;
    switch(state) {
        case TicketState::TODO:
            doable = currentState->startAnalysing(ticket , u);
            finalState = new Todo();
            break;
        case TicketState::REVIEW:
            doable = currentState->startReviewing(ticket ,  u);
            finalState = new Review();
            break;
        case TicketState::DONE:
            doable = currentState->markDone(ticket , u);
            finalState = new Done();
            break;
    }

    if(doable) { // if two threads got doable as true both will try to access at the same time this piece of code, that leads to race condition , so use mutex
        mtx.lock();
        ticket->setJiraState(finalState);
        cout << "State changed successfully" << endl;
        mtx.unlock();
    } else {
        cout << "State change failed" << endl;
    }
}
};
TicketService* TicketService::ticketServiceInstance = nullptr;
mutex TicketService::mtx;
#endif