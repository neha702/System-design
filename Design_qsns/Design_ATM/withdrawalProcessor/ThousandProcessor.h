#ifndef THOUSANDPROCESSOR_H
#define THOUSANDPROCESSOR_H
#include "cashWithdrawProcessor.h"
#include "../ATMService.h"
using namespace std;


class ThousandProcessor : public CashWithDrawProcessor {
public:
ThousandProcessor(CashWithDrawProcessor* nextProcessor) : CashWithDrawProcessor(nextProcessor) {}

bool withdrawCash(int amount , Card* card) { // amount => to be withdrawn
    ATMService* service = ATMService::getInstance();
    int balance = card->getBalance();
    int notes = amount / 1000;

    if(service->getBalance() < amount) {
        cout << "Insufficient balance in atm , please try later" << endl;
        return false;
    }

    if(balance < amount) {
        cout << "Insufficient balance in your account , please try later" << endl;
        return false;
    }

    if(notes > service->getThousandNotes()) {
        cout << "Insufficient number of notes , passing to next processor!" << endl;
        amount -= (service->getThousandNotes() * 1000);
        balance -= (service->getThousandNotes() * 1000);
        card->setBalance(balance);
        service->setThousandNotes(0);
    }else if(notes <= service->getThousandNotes() && amount >= 1000) {
        balance -= (notes * 1000);
        amount -= (notes * 1000);
        card->setBalance(balance);
        service->setThousandNotes(service->getThousandNotes() - notes);
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

#endif // THOUSANDPROCESSOR_H