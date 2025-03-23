#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H
#include "atmStates.h"
#include <iostream>
using namespace std;

class CheckBalance : public ATMStates{
public:
void insertCard() {
    cout << "Card is already inserted" << endl;
}

bool authenticateWithPin(Card* card , int pin) {
    cout << "Card already authenticated" << endl;
}

ATMStates* selectOperations(TransactionType operation) {
    cout << "Operation already selected!" << endl;
}

void exit() {
    cout << "Exit from this state not possible!" << endl;
}

void returnCard() {
    cout << "Please collect your card" << endl;
}

bool withdraw(int amount , Card* card) {
    cout << "Already operation selected , so can't withdraw amount!" << endl;
    return false;
}

int displayBalance(Card* card) {
    return card->getBalance();
}
};

#endif // CHECKBALANCE_H