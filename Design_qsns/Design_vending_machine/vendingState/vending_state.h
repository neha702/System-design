#ifndef VENDING_STATE_H
#define VENDING_STATE_H
#include "../denomination.h"
#include "../product.h"

class VendingState {
public:
virtual void insertDenomination(Denomination* denomination) = 0;
virtual Product* pressButton(int productCode) = 0;
virtual int dispenseChange(Product* product) = 0;
//virtual void transactionCancelled() = 0;
};

#endif // VENDING_STATE_H