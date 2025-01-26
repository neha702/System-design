#ifndef EXIT_H
#define EXIT_H

#include "costComputorManager.h"
#include "ticket.h"
#include "payment.h"
#include "payment_factory.h"
#include "parkingSpot_manager.cpp"
#include <ctime>


class Exit {
CostComputorManager* costComputorManager;
PaymentFactory* paymentFactoryObj;
ParkingSpotManager* parkingSpotManager;
Payment* paymentObj;
public:
Exit(CostComputorManager* costComputorManager , PaymentFactory* paymentFactoryObj , ParkingSpotManager* parkingSpotManager , Payment* paymentObj){
    this->costComputorManager = costComputorManager;
    this->paymentFactoryObj = paymentFactoryObj;
    this->parkingSpotManager = parkingSpotManager;
    this->paymentObj = paymentObj;
}

int calculateParkingCost(Ticket* ticket , PriceStrategy* strategy) {
    return costComputorManager->calculateParkingCost(ticket , strategy);
}

void makePayment(Ticket* ticket , string paymentType) {
    PaymentStrategy* paymentStrategy = paymentFactoryObj->getPaymentStrategyObj(paymentType);
    int price = ticket->getParkingSpot()->getPrice();
    paymentObj->performPayment(price , paymentStrategy); 
}

void updateParkingSpot(Ticket* ticket) {
ticket->getParkingSpot()->resetSpot();
cout << " Parking spot is now empty!" << endl;
}

};
#endif