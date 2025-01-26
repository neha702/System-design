#ifndef PARKING_LOT_H
#define PARKING_LOT_H
#include<vector>
#include "entrance.h"
#include "exit.h"
#include<mutex>


class ParkingLot {
vector<Entrance*>entrances;
vector<Exit*>exits;
static ParkingLot* parkingLot;
static mutex mtx;
public:
static ParkingLot* getParkingLot() {
if(!parkingLot) {
    mtx.lock();
    if (!parkingLot) {
         parkingLot = new ParkingLot();
         cout << "Parking lot created!" << endl;
    }
    mtx.unlock();
 }
return parkingLot;
}

void addEntrance(Entrance* entrance) {
entrances.push_back(entrance);
cout << "Entrance added to parking lot!" << endl;
}

void addExit(Exit* exit) {
cout << "Exit is added" << endl;
exits.push_back(exit);
}
};

ParkingLot* ParkingLot::parkingLot = nullptr;
std::mutex ParkingLot::mtx;

#endif
