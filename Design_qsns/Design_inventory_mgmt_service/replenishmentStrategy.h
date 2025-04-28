#ifndef REPLENISHMENTSTRATEGY_H
#define REPLENISHMENTSTRATEGY_H
#include "product.h"

class ReplenishmentStrategy {
public:
    virtual bool checkForReplenish(Product* p) = 0;
    virtual void replenish(Product* p) = 0;
};

class ReorderPointStrategy : public ReplenishmentStrategy {
public:
    bool checkForReplenish(Product* p) {
        return (p->getQuantity() < p->getThreshold());
    }
    
    void replenish(Product* p) {
        p->addStock(5);
    }
};

// class JustInTimeStrategy : public ReplenishmentStrategy {
// public:
//     void replenish(Product* p) {
        
//     }
// };

#endif // REPLENISHMENTSTRATEGY_H