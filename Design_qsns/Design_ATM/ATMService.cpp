#include "ATMService.h"
#include "states/selectOperationState.h"
#include "states/cashWithdrawalState.h"
#include "states/idleState.h"
#include "states/hasCardState.h"

ATMService* ATMService::atmServiceInstance = nullptr;
mutex ATMService::instanceMutex;
ATMStates* ATMService::currState = nullptr;

ATMService* ATMService::getInstance() {
    lock_guard<mutex> lock(instanceMutex);
    if (!atmServiceInstance) {
        atmServiceInstance = new ATMService();
        currState = new IdleState();
    }
    return atmServiceInstance;
}

void ATMService::setNotes(int thousand, int fiveHundred, int hundred) {
    thousandNotes = thousand;
    fiveHundredNotes = fiveHundred;
    hundredNotes = hundred;
}

void ATMService::setBalance(int bal) { balance = bal; }

void ATMService::insertCard(Card* card) {
    currState->insertCard();
    currState = new HasCardState();
}

void ATMService::selectOperation(TransactionType txnType) {
    ATMStates* newState = currState->selectOperations(txnType);
    if(newState == nullptr){
        currState->exit();
        currState->returnCard();
        currState = new IdleState();
        return;
    }
    currState = newState;
}

bool ATMService::authenticateWithPin(Card* card, int pin) {
    bool success = currState->authenticateWithPin(card, pin);
    if (success) {
        cout << "Authentication successful!" << endl;
        currState = new SelectOpsState();
    } else {
        cout << "Authentication failed!" << endl;
        currState->exit();
        currState->returnCard();
        currState = new IdleState();
    }
    return success;
}

void ATMService::withdrawCash(int amount, Card* card) {
        bool success = currState->withdraw(amount, card);
        if (success) {
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Withdrawal failed!" << endl;
        }
        currState->exit();
        currState->returnCard();
        currState = new IdleState();
}

void ATMService::displayBalance(Card* card) {
        int balance = currState->displayBalance(card);
        cout << "Available balance: " << balance << endl;
        currState = new SelectOpsState();
}

void ATMService::initialize(int balance, int thousandNotes, int fiveHundredNotes, int hundredNotes) {
    ATMService::setHundredNotes(hundredNotes); 
    ATMService::setFiveHundredNotes(fiveHundredNotes); 
    ATMService::setThousandNotes(thousandNotes);
    ATMService::setBalance(balance);
}

int ATMService::getThousandNotes() { return thousandNotes; }
int ATMService::getFiveHundredNotes() { return fiveHundredNotes; }
int ATMService::getHundredNotes() { return hundredNotes; }
int ATMService::getBalance() { return balance; }

void ATMService::setThousandNotes(int notes) { thousandNotes = notes; }
void ATMService::setFiveHundredNotes(int notes) { fiveHundredNotes = notes; }
void ATMService::setHundredNotes(int notes) { hundredNotes = notes; }
