#ifndef SELECTOPERATIONSTATE_H
#define SELECTOPERATIONSTATE_H
#include "atmStates.h"
#include "cashWithdrawalState.h"
#include "checkBalance.h"
#include <iostream>
using namespace std;


class SelectOpsState : public ATMStates {
public:
ATMStates* selectOperations(TransactionType operation) {
    switch(operation) {
        case TransactionType::CASH_WITHDRAWAL : {
            return new CashWithdrawalState();
        }
        case TransactionType::BALANCE_ENQUIRY :{
            return new CheckBalance();
        }
        default: {
            cout << "Invalid operation selected" << endl;
            return nullptr;
        }
    }
}

void insertCard() {
    cout << "Card is already inserted" << endl;
}

bool authenticateWithPin(Card* card , int pin) {
    cout << "Card is already inserted " << endl;
    return false;
}

void exit() {
    cout << "Exit from session!" << endl;
}

void returnCard() {
    cout << "Please collect your card" << endl;
}

bool withdraw(int amount , Card* card) {
    cout << "Still need to select operation, can't withdraw cash." << endl;
    return false;
}

int displayBalance(Card* card) {
     cout << "Still need to select operation, can't display amount" << endl;
     return 0;
}


};

#endif // SELECTOPERATIONSTATE_H