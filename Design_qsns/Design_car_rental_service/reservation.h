#ifndef RESERVATION_H
#define RESERVATION_H
#include "user.h"
#include "vehicle.h"
#include "location.h"

class Reservation
{
    int id;
    User *user;
    Vehicle *vehicle;
    Location *dropPoint;
    Location *pickPoint;
    long hours;

public:
    Reservation(int id, User *user, Vehicle *vehicle, Location *pickPoint , Location *dropPoint , long hours)
    {
        this->id = id;
        this->user = user;
        this->vehicle = vehicle;
        this->dropPoint = dropPoint;
        this->pickPoint = pickPoint;
        this->hours = hours;
    }

    Vehicle *getVehicle()
    {
        return vehicle;
    }

    Location* getPickupLocation()
    {
        return pickPoint;
    }

     Location* getDropLocation()
    {
        return dropPoint;
    }

    long getHours()
    {
        return hours;
    }

    User* getUser() {
        return user;
    }

    int getReservationId() {
        return id;
    }
};

#endif // RESERVATION_H