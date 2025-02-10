#include "../../bitsStd.h"
#include "jiraUser.h"
#include "ticketEnum.h"
#include "ticketService.h"
#include "jiraTicket.h"
using namespace std;

int main() {
    JiraUser* u1 = new JiraUser("Neha");
    TicketService* ticketService = TicketService::getTicketServiceInstance();
    JiraTicket* ticket = ticketService->createTicket(u1 , "Design meeting scheduler");
    ticketService->changeTicketState(ticket , TicketState::REVIEW, u1);
    ticketService->changeTicketState(ticket , TicketState::DONE, u1);
    ticketService->changeTicketState(ticket , TicketState::DONE, u1);
    // ticketService->changeTicketState(ticket , TicketState::TODO, u1);
    return 0;
}