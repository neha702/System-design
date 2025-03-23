#ifndef ATMSERVICE_H
#define ATMSERVICE_H

#include <mutex>
#include "card.h"
#include "states/atmStates.h"

using namespace std;

class ATMService {
public:
    static ATMService* getInstance();

    void setNotes(int thousand, int fiveHundred, int hundred);
    void setBalance(int bal);

    void insertCard(Card* card);
    void selectOperation(TransactionType txnType);
    void withdrawCash(int amount, Card* card);
    void displayBalance(Card* card);
    bool authenticateWithPin(Card* card, int pin);

    int getThousandNotes();
    int getFiveHundredNotes();
    int getHundredNotes();
    int getBalance();

    void initialize(int balance, int thousandNotes, int fiveHundredNotes, int hundredNotes);

    void setThousandNotes(int notes);
    void setFiveHundredNotes(int notes);
    void setHundredNotes(int notes);

private:
    ATMService() = default;

    static ATMService* atmServiceInstance;
    static mutex instanceMutex;
    static ATMStates* currState;

    int balance = 0;
    int thousandNotes = 0;
    int fiveHundredNotes = 0;
    int hundredNotes = 0;
};

#endif // ATMSERVICE_H
