#ifndef CASHWITHDRAWALSTATE_H
#define CASHWITHDRAWALSTATE_H
#include "atmStates.h"
#include "../withdrawalProcessor/HundredProcessor.h"
#include "../withdrawalProcessor/FiveHundredProcessor.h"
#include "../withdrawalProcessor/ThousandProcessor.h"

class CashWithdrawalState : public ATMStates {
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
    cout << "Exit session!" << endl;
}

void returnCard() {
    cout << "Please collect your card" << endl;
}

bool withdraw(int amount , Card* card) {
    CashWithDrawProcessor* withdrawProcessor = new ThousandProcessor(new FiveHundredProcessor(new HundredProcessor(nullptr)));
    return withdrawProcessor->withdrawCash(amount , card);
}

int displayBalance(Card* card) {
     cout << "Already operation selected , so can't display amount!" << endl;
     return 0;
}

};

#endif // CASHWITHDRAWALSTATE_H