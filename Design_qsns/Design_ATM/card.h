#ifndef CARD_H
#define CARD_H
#include "bankAccount.h"

class Card {
long cardNum;
int CVV;
long expiryDate;
int pin = 1235; //setting one pin for all cards
BankAccount* bankAccount;
public:
    Card(long cardNum , int CVV , long expiryDate , BankAccount* bankAccount ) {
        this->cardNum = cardNum;
        this->CVV = CVV;
        this->expiryDate = expiryDate;
        this->bankAccount = bankAccount;
    }

    int getPin() {
        return pin;
    }

    int getBalance() {
        return bankAccount->getBalance();
    }

    void setBalance(int amount) {
        bankAccount->setBalance(amount);
    }
};

#endif // CARD_H