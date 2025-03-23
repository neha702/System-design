#ifndef HUNDREDPROCESSOR_H
#define HUNDREDPROCESSOR_H
#include "cashWithdrawProcessor.h"
#include <iostream>
#include "../ATMService.h"
using namespace std;

class HundredProcessor : public CashWithDrawProcessor {
public:
HundredProcessor(CashWithDrawProcessor* nextProcessor) : CashWithDrawProcessor(nextProcessor) {}

bool withdrawCash(int amount , Card* card) { // amount => to be withdrawn
    ATMService* service = ATMService::getInstance();
    int balance = card->getBalance();
    int notes = amount / 100;

    if(service->getBalance() < amount) {
        cout << "Insufficient balance in atm , please try later" << endl;
        return false;
    }

    if(balance < amount) {
        cout << "Insufficient balance in your account , please try later" << endl;
        return false;
    }

    if(notes > service->getHundredNotes()) {
        cout << "Insufficient number of notes , passing to next processor!" << endl;
        amount -= (service->getHundredNotes() * 100);
        balance -= (service->getHundredNotes() * 100);
        card->setBalance(balance);
        service->setHundredNotes(0);
    } else if(notes <= service->getHundredNotes() && amount >= 100) {
        balance -= (notes * 100);
        card->setBalance(balance);
        amount -= (notes * 100);
        service->setHundredNotes(service->getHundredNotes() - notes);
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

    cout << "Amount withdrawn successfully" << endl;
    return true;
}
};

#endif // HUNDREDPROCESSOR_H