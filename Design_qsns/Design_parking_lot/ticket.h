#ifndef TICKET_H
#define TICKET_H
#include "parking_spot.h"

class Ticket {
long entryTime;
ParkingSpot* parkingSpot;
public:
Ticket(long entryTime , ParkingSpot* parkingSpot) {
    this->entryTime = entryTime;
    this->parkingSpot = parkingSpot;
    cout << "Ticket for parking spot " << parkingSpot->getSpotType() << " is created!" << endl;
}

long getEntryTimestamp() {
    return entryTime;
}

ParkingSpot* getParkingSpot() {
    return parkingSpot;
}
};

#endif