#ifndef RENTAL_SERVICE_MANAGER_H
#define RENTAL_SERVICE_MANAGER_H
#include "car_rental_service.h"
#include "vehicle.h"
#include "location.h"
#include "notification.h"

class RentalServiceManager {
vector<Vehicle*> vehicles;
vector<Location*> locations;
public:
static unordered_map<Location* , set<Vehicle*> > locationAvailableVehicleMap;
static set<Observer*> observerList;

void addVehicle(Vehicle* v) {
    vehicles.push_back(v);
    cout << "Vehicle " << v->getVehicleId() << " added to the vehicle list" << endl;
}

void addObserver(Observer* ob) {
    observerList.insert(ob);
}

void removeObserver(Observer* ob) {
    observerList.erase(ob);
}

void addLocation(Location* l) {
    locations.push_back(l);
    cout << "Location " << l->getCity() << " added to the location list" << endl;
}

void assignVehicleToLocation(Vehicle* v , Location* l) {
    locationAvailableVehicleMap[l].insert(v);
    cout << "Vehicle " << v->getVehicleId() << " added to location " << l->getCity() << endl;
}

void removeVehicleFromLocation(Vehicle* v , Location* l) {
    //cout << "actual size is " << locationAvailableVehicleMap[l].size() << endl;
    locationAvailableVehicleMap[l].erase(v);
    //cout << "size is " << locationAvailableVehicleMap[l].size() << endl;
    cout << "Vehicle " << v->getVehicleId() << " removed from location since it is booked" << endl;
}
};
unordered_map<Location* , set<Vehicle*> > RentalServiceManager::locationAvailableVehicleMap;
set<Observer*> RentalServiceManager::observerList;
#endif // RENTAL_SERVICE_MANAGER_H