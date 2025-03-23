#ifndef HASCARDSTATE_H
#define HASCARDSTATE_H
#include "../card.h"
#include "atmStates.h"
#include <iostream>
using namespace std;

class HasCardState : public ATMStates{
public:
void insertCard() {
    cout << "Card is already inserted" << endl;
}

bool authenticateWithPin(Card* card , int pin) {
    return (pin == card->getPin());
}

ATMStates* selectOperations(TransactionType operation) {
    cout << "Card is not yet authenticated , so can't select operations!" << endl;
}

void exit() {
    cout << "Exit from session!" << endl;
}

void returnCard() {
    cout << "Please collect your card" << endl;
}

bool withdraw(int amount , Card* card) {
    cout << "No operation selected , so can't withdraw amount!" << endl;
    return false;
}

int displayBalance(Card* card) {
    cout << "No operation selected , so can't display amount!" << endl;
    return 0;
}
};

#endif // HASCARDSTATE_H