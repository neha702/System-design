#ifndef DISPENSE_PRODUCT_STATE_H
#define DISPENSE_PRODUCT_STATE_H
#include "vending_state.h"
#include "../vendingMachine.h"
using namespace std;

class DispenseProductState : public VendingState {
void insertDenomination(Denomination* denomination) {
    cout << "Another transaction is in progress , can't insert denomination!" << endl;
}

Product* pressButton(int productCode) {
   cout << "Another transaction is in progress , can't select product!" << endl;
   return nullptr;
}

int dispenseChange(Product* product) {
   // cout << VendingMachineManager::getBalance() << " " << product->getPrice() << endl;
   int returnAmount = VendingMachineManager::getBalance() - product->getPrice();
   if(returnAmount != 0) {
    cout << "Change dispensed of amount " << returnAmount << endl;
   }
   return returnAmount;
}

Product* dispenseProduct() {
 cout << "Coin/Note hasn't been inserted yet!" << endl;
 return nullptr;
}

// void transactionCancelled() {
// cout << "Transaction can't be cancelled!" << endl;
//  return;
// }
};

#endif // DISPENSE_PRODUCT_STATE_H