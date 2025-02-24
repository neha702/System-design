#ifndef IDLE_STATE_H
#define IDLE_STATE_H
#include "vending_state.h"
#include "../vendingMachine.h"
using namespace std;


class IdleState : public VendingState {
public:
void insertDenomination(Denomination* denomination) {
    int balance = VendingMachineManager::getBalance();
    VendingMachineManager::updateBalance(denomination->getPrice());
    cout << "Denomination inserted of price " << denomination->getPrice() << endl;
}

Product* pressButton(int productCode) {
   cout << "Please insert coin/note before selecting product!" << endl;
   return nullptr;
}

int dispenseChange(Product* product) {
    cout << "Coin/Note hasn't been inserted yet!" << endl;
}

Product* dispenseProduct() {
 cout << "Coin/Note hasn't been inserted yet!" << endl;
 return nullptr;
}

// void transactionCancelled() {
// cout << "No transaction is in progress!" << endl;
//  return;
// }
};

#endif // IDLE_STATE_H