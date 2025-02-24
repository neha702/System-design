#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "product.h"
#include "denomination.h"
#include "vendingState/vending_state.h"
#include "vendingMachineManager.h"
#include "vendingState/idle_state.h"
#include "vendingState/coin_inserted_state.h"
#include "vendingState/dispense_product_state.h"
#include <iostream>
#include <unordered_map>
using namespace std;

class VendingMachine {
public:
static VendingMachine* vendingMachineInstance;
static mutex mtx;
static VendingMachineManager* vendingMachineManagerInstance;
static VendingState* vendingState;

static VendingMachineManager* getVendingMachineManager() {
    return vendingMachineManagerInstance;
}

static VendingMachine* getVendingMachineInstance() {
    if(vendingMachineInstance == nullptr) {
        mtx.lock();
        if(vendingMachineInstance == nullptr) {
            vendingMachineInstance = new VendingMachine();
            vendingMachineManagerInstance = new VendingMachineManager();
            vendingState = new IdleState();
        }
        mtx.unlock();
    }
    return vendingMachineInstance;
}

void insertDenomination(Denomination* denomination) {
    vendingState->insertDenomination(denomination);
    vendingState = new CoinInsertedState();
}

Product* pressButton(int productCode) {
   Product* p =vendingState->pressButton(productCode);
   vendingState = new DispenseProductState();
   return p;
}

int returnChange(Product* p) {
   int change = vendingState->dispenseChange(p);
   vendingState = new IdleState();
   return change;
}
};
VendingMachine* VendingMachine::vendingMachineInstance = nullptr;
mutex VendingMachine::mtx;
VendingMachineManager* VendingMachine::vendingMachineManagerInstance = nullptr;
VendingState* VendingMachine::vendingState;

#endif // VENDINEMACHINE_H