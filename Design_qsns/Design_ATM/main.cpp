#include "../../bitsStd.h"
#include "ATMService.h"

using namespace std;

int main() {
    ATMService* atmService = ATMService::getInstance();
    atmService->initialize(10000 , 10 , 10 , 10);
    BankAccount* bankAccount = new BankAccount(10001, 1234 , 5000);
    Card* card = new Card(1236 , 12 , 1738900 , bankAccount);

    atmService->insertCard(card);
    int pin = 0;
    cout << "Enter pin:" << endl;
    cin >> pin;
    bool success = atmService->authenticateWithPin(card , pin);
    if(!success) {
        return 0;
    }
    atmService->selectOperation(TransactionType::CASH_WITHDRAWAL);
    atmService->withdrawCash(6000 , card);
    //atmService->displayBalance(card);
}