#ifndef COIN_INSERTED_STATE_H
#define COIN_INSERTED_STATE_H
#include <iostream>
using namespace std;
#include "vending_state.h"
#include "../vendingMachine.h"
using namespace std;

class CoinInsertedState : public VendingState {
public:
void insertDenomination(Denomination* denomination) {
    cout << "Coin is already inserted of price " << denomination->getPrice() << endl;
}

Product* pressButton(int productCode) {
    Product* product = VendingMachineManager::getProductByCode(productCode);
   if(product != nullptr) {
        cout << "Product chosen with product code " << productCode << endl; 
        return product;
   }
   return nullptr;
}

int dispenseChange(Product* product) {
    cout << "Product not yet chosen!" << endl;
}

Product* dispenseProduct() {
 cout << "Product not yet chosen!" << endl;
 return nullptr;
}

// void transactionCancelled() {
// cout << "No transaction is in progress!" << endl;
//  return;
// }
};

#endif // COIN_INSERTED_STATE_H