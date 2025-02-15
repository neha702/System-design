#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "location.h"
#include "enums.h"

using namespace std;

class Vehicle {
public:
string name;
long id;
Location* location;
Status status;
VehicleType vehicleType;
long price;
Vehicle(string name , long id , Status status , VehicleType vehicleType , long hourlyPrice) {
   this->name = name;
   this->id = id;
   this->location = nullptr;
   this->status = status;
   this->vehicleType = vehicleType;
   this->price = hourlyPrice;
}

void setLocation(Location* location) {
   this->location = location;
}

void bookVehicle() {
    this->status = Status::BOOKED;
    cout << "Vehicle " << id << " is booked!" << endl;
}

void releaseVehicle() {
    this->status = Status::AVAILABLE;
    cout << "Vehicle " << id << " is returned!" << endl;
}

int getVehicleId() {
    return id;
}

long getVehiclePrice() {
    return price;
}

Status getVehicleStatus() {
    return status;
}
};

#endif // VEHICLE_H