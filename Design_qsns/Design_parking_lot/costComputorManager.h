#ifndef COSTCOMPUTOR_MANAGER
#define COSTCOMPUTOR_MANAGER
#include "ticket.h"

class PriceStrategy {
public:
virtual int findPrice(Ticket* ticket) = 0;
};

class HourlyPriceStrategy : public PriceStrategy {
public:
int findPrice(Ticket* ticket) {
    std::time_t currentTime = std::time(nullptr);
    long currTimestamp = static_cast<long>(currentTime) + 3600; 
    long entryTimestamp = ticket->getEntryTimestamp();
    int price = ticket->getParkingSpot()->getPrice();

    int prices = ((currTimestamp - entryTimestamp) / 3600)* price;
    cout << "Price computed is " << prices << endl;
}
};

class MinutePriceStrategy : public PriceStrategy {
public:
int findPrice(Ticket* ticket) {
    std::time_t currentTime = std::time(nullptr);
    long currTimestamp = static_cast<long>(currentTime); 
    long entryTimestamp = ticket->getEntryTimestamp();
    int price = ticket->getParkingSpot()->getPrice();

    int prices = ((currTimestamp - entryTimestamp) / 60)* price;
    cout << "Price computed is " << prices << endl;
}
};

class CostComputorManager{
PriceStrategy* priceStrategy;
public:
CostComputorManager(PriceStrategy* strategy) {
    this->priceStrategy = strategy;
}
virtual int calculateParkingCost(Ticket* ticket , PriceStrategy* priceStrategy) {
    return priceStrategy->findPrice(ticket);
}
};

#endif