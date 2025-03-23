#ifndef ATMSTATES_H
#define ATMSTATES_H
#include "../card.h"
#include "../transactionType.h"
using namespace std;

class ATMStates {
public:
virtual void insertCard() = 0;
virtual bool authenticateWithPin(Card* card , int pin) = 0;
virtual ATMStates* selectOperations(TransactionType operation) = 0;
virtual void exit() = 0;
virtual void returnCard() = 0;
virtual bool withdraw(int amount , Card* card) = 0;
virtual int displayBalance(Card* card) = 0;
};

#endif // ATMSTATES_H