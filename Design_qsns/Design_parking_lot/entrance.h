#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "parkingSpot_factory.h"
#include "parkingSpot_manager.cpp"
#include "ticket.h"
#include <ctime>

class Entrance {
ParkingSpotManager* parkingSpotManager;
ParkingSpotFactory* parkingSpotFactory;
public:
Entrance(ParkingSpotFactory* parkingSpotFactory) {
    this->parkingSpotFactory = parkingSpotFactory;
    cout << "Entrance created!" << endl;
}

ParkingSpot* findParkingSpace(string vehicleType , vector<ParkingSpot*>ParkingSpotList) {
    parkingSpotManager = parkingSpotFactory->getParkingSpotManager(vehicleType);
    return parkingSpotManager->findParkingSpot(ParkingSpotList);
}

void bookParkingSpot(ParkingSpot* parkingSpot , Vehicle* v) {
    parkingSpot->parkVehicle(v);
}

Ticket* generateTicket(ParkingSpot* ps) {
     std::time_t currentTime = std::time(nullptr);

    long timestampAsLong = static_cast<long>(currentTime);

    Ticket* ticket = new Ticket(timestampAsLong , ps);

    return ticket;
}

};

#endif