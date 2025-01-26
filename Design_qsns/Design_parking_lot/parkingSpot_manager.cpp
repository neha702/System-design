#ifndef PARKINGSPOT_MANAGER
#define PARKINGSPOT_MANAGER
#include "parking_spot.h"
#include <vector>
#include<mutex>

//parking spot strategy to think of

// class ParkingSpotStrategy {
// public:
// virtual ParkingSpot* findSpace() {
// for(int i = 0 ; i < )
// }
// };

// class NearEntranceParkingSpotStrategy : public ParkingSpotStrategy {
// public:
// ParkingSpot* findSpace() {

// }
// };

class ParkingSpotManager{
static ParkingSpotManager* parkingSpotManagerInstance;
static mutex mtx;
public:
static ParkingSpotManager* getParkingSpotManager() {
 if(!parkingSpotManagerInstance) {
    mtx.lock();
    if(!parkingSpotManagerInstance) {
        parkingSpotManagerInstance = new ParkingSpotManager();
    }
    mtx.unlock();
 }
 cout << "Parking spot manager created!" << endl;
return parkingSpotManagerInstance;
}

void addParkingSpot(string vehicleType , vector<ParkingSpot*>&ParkingSpotList) {
    if(vehicleType == "Two_Wheeler") {
        ParkingSpot* twoWheelerPS = new TwoWheelerParkingSpot();
        ParkingSpotList.push_back(twoWheelerPS);
        cout << "Parking spot for two wheeler created!" << endl;
    } else if (vehicleType == "Four_Wheeler") {
        ParkingSpot* fourWheelerPS = new FourWheelerParkingSpot();
        ParkingSpotList.push_back(fourWheelerPS);
        cout << "Parking spot for four wheeler created!" << endl;
    }
}

// void removeParkingSpot(int id) {
//     if(id >= 0 && id < ParkingSpotList.size()) {
//         ParkingSpotList.erase(ParkingSpotList.begin() + id);
//     } else{
//         throw runtime_error("Index out of bounds!");
//     }
// }

virtual ParkingSpot* findParkingSpot(vector<ParkingSpot*>ParkingSpotList){};
};

class TwoWheelerParkingSpotManager : public ParkingSpotManager {
public:
TwoWheelerParkingSpotManager() {
    cout << "Parking spot manager for two wheeler created!" << endl;
}
ParkingSpot* findParkingSpot(vector<ParkingSpot*>ParkingSpotList){
    for(auto parkingSpot : ParkingSpotList) {
        if(parkingSpot->getSpotType() == "Two_Wheeler" && !parkingSpot->emptySpotCheck()) {
            return parkingSpot;
        }
    }
    return nullptr;
}
};

class FourWheelerParkingSpotManager : public ParkingSpotManager {
public:
FourWheelerParkingSpotManager() {
    cout << "Parking spot manager for four wheeler created!" << endl;
}
ParkingSpot* findParkingSpot(vector<ParkingSpot*>ParkingSpotList) {
    for(auto parkingSpot : ParkingSpotList) {
        if(parkingSpot->getSpotType() == "Four_Wheeler" && !parkingSpot->emptySpotCheck()) return parkingSpot;
    }
    return nullptr;
}
};
ParkingSpotManager* ParkingSpotManager::parkingSpotManagerInstance = nullptr;
mutex ParkingSpotManager::mtx;

#endif