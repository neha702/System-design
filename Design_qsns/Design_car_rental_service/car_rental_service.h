#ifndef CAR_RENTAL_SERVICE_H
#define CAR_RENTAL_SERVICE_H
#include<mutex>
#include <unordered_map>
#include "rental_service_manager.h"
#include "reservation.h"
#include "paymentProcessor.h"
#include "notification.h"
using namespace std;

class CarRentalService {
public:
static RentalServiceManager* rentalServiceManagerInstance;
static CarRentalService* carRentalserviceInstance;
static mutex mtx;
static PaymentProcessor* paymentProcessorInstance;
static CarRentalService* getInstance() {
    if(carRentalserviceInstance == nullptr) {
        mtx.lock();
        if(carRentalserviceInstance == nullptr) {
            carRentalserviceInstance = new CarRentalService();
            rentalServiceManagerInstance = new RentalServiceManager();
            paymentProcessorInstance = new PaymentProcessor();
        }
        mtx.unlock();
    }
}

vector<Vehicle*> getVehiclesByLocation(Location* location) {
    set<Vehicle*>vehicleList = RentalServiceManager::locationAvailableVehicleMap[location];
    return vector<Vehicle*>(vehicleList.begin() , vehicleList.end());
}

void bookVehicle(Reservation* reservation) {
    Vehicle* v = reservation->getVehicle();
    Location* pickupPoint = reservation->getPickupLocation();
    v->bookVehicle();
    rentalServiceManagerInstance->removeVehicleFromLocation(v , pickupPoint);
}

void returnVehicle(Reservation* reservation) {
    Vehicle* v = reservation->getVehicle();
    Location* dropPoint = reservation->getDropLocation();
    v->releaseVehicle();
    rentalServiceManagerInstance->assignVehicleToLocation(v , dropPoint);
}

void performPayment(Reservation* reservation , PaymentStrategy* paymentModeStrategy) {
    //compute cost and pay
    int amount = reservation->getVehicle()->getVehiclePrice() * reservation->getHours();
    paymentProcessorInstance->setPaymentStrategy(paymentModeStrategy);
    paymentProcessorInstance->processPayment(amount);
}

void notify(Reservation* reservation) {
    set<Observer*>observerList = RentalServiceManager::observerList;
    for(auto observer: observerList) {
        observer->notify(reservation);
    }
}
};

CarRentalService* CarRentalService::carRentalserviceInstance = nullptr;
mutex CarRentalService::mtx;
RentalServiceManager* CarRentalService::rentalServiceManagerInstance = nullptr;
PaymentProcessor* CarRentalService::paymentProcessorInstance = nullptr;


#endif // CAR_RENTAL_SERVICE_H