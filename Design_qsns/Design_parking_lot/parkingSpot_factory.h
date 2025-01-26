#ifndef PARKINGSPOT_FACTORY
#define PARKINGSPOT_FACTORY
#include "parking_spot.h"
#include "parkingSpot_manager.cpp"
#include <vector>

class ParkingSpotFactory{
public:
ParkingSpotManager* getParkingSpotManager(string vehicleType) {
    ParkingSpotManager* parkingSpotManager;
    if(vehicleType == "Two_Wheeler") {
        parkingSpotManager =  new TwoWheelerParkingSpotManager();
    } else if (vehicleType == "Four_Wheeler") {
        parkingSpotManager = new FourWheelerParkingSpotManager();
    }
    return parkingSpotManager;
}
};


#endif