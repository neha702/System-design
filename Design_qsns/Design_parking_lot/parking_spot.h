#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H
#include "vehicle.h"

class ParkingSpot {
int id;
int price;
bool isEmpty = false;
Vehicle* vehicle;
protected:
string spotType;
public:
void parkVehicle(Vehicle* v) {
    vehicle = v;
    isEmpty = true;
    cout << "Vehicle " << id << " is parked" << endl;
}

void removeVehicle() {
    vehicle = nullptr;
    isEmpty = false;
}

virtual int getPrice() = 0;

string getSpotType() {
    return spotType;
}

bool emptySpotCheck() {
    return isEmpty;
}

void resetSpot() {
    isEmpty = false;
}

};

class TwoWheelerParkingSpot : public ParkingSpot {
public:
TwoWheelerParkingSpot() {
    spotType = "Two_Wheeler";
}

int getPrice() {
    return 10;
}

};

class FourWheelerParkingSpot : public ParkingSpot{
public:
FourWheelerParkingSpot() {
    spotType = "Four_Wheeler";
}

int getPrice() {
    return 20;
}

};

#endif