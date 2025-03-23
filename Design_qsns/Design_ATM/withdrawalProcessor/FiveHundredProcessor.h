#ifndef FIVEHUNDREDPROCESSOR_H
#define FIVEHUNDREDPROCESSOR_H
#include "cashWithdrawProcessor.h"
#include <iostream>
#include "../ATMService.h"

using namespace std;

class FiveHundredProcessor : public CashWithDrawProcessor {
public:
FiveHundredProcessor(CashWithDrawProcessor* nextProcessor) : CashWithDrawProcessor(nextProcessor) {}

bool withdrawCash(int amount , Card* card) { // amount => to be withdrawn
    ATMService* service = ATMService::getInstance();
    int balance = card->getBalance();
    int notes = amount / 500;

    if(service->getBalance() < amount) {
        cout << "Insufficient balance in atm , please try later" << endl;
        return false;
    }

    if(balance < amount) {
        cout << "Insufficient balance in your account , please try later" << endl;
        return false;
    }

    if(notes > service->getFiveHundredNotes()) {
        cout << "Insufficient number of notes , passing to next processor!" << endl;
        amount -= (service->getFiveHundredNotes() * 500);
        balance -= (service->getFiveHundredNotes() * 500);
        card->setBalance(balance);
        service->setFiveHundredNotes(0);
    } else if(notes <= service->getFiveHundredNotes() && amount >= 500) {
        balance -= (notes * 500);
        amount -= (notes * 500);
        card->setBalance(balance);
        service->setFiveHundredNotes(service->getFiveHundredNotes() - notes);
    }

    if(amount != 0 && nextProcessor != nullptr) {
        bool canProcess = nextProcessor->withdrawCash(amount , card);
        if(canProcess) {
            cout << "Amount withdrawn successfully" << endl;
        }
        return canProcess;
    }

     if(amount != 0 && nextProcessor == nullptr) {
        cout << "Can't process the amount due to insufficient amount of notes" << endl;
        return false;
    }

    cout <<"Amount withdrawn successfully" << endl;
    return true;
}
};

#endif // FIVEHUNDREDPROCESSOR_H