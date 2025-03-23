#ifndef IDLESTATE_H
#define IDLESTATE_H
#include <iostream>
using namespace std;
#include "atmStates.h"

class IdleState : public ATMStates {
void insertCard() {
    cout << "Card is inserted" << endl;
}

bool authenticateWithPin(Card* card , int pin) {
   cout << "Can't authenticate , since card is not yet inserted!" << endl;
}

ATMStates* selectOperations(TransactionType operation) {
    cout << "Card is not yet inserted , so can't select operations!" << endl;
}

void exit() {
    cout << "Can't exit from this state since card not yet inserted!" << endl;
}

void returnCard() {
    cout << "Can't return since card not inserted yet" << endl;
}

bool withdraw(int amount , Card* card) {
    cout << "Card not inserted so can't withdraw amount" << endl;
    return false;
}

int displayBalance(Card* card) {
     cout << "Card not inserted so can't display amount" << endl;
     return 0;
}
};

#endif // IDLESTATE_H