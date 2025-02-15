#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <iostream>
#include "reservation.h"
using namespace std;

class Observer {
public:
virtual void notify(Reservation* reservation) = 0;
};

class EmailNotiifer : public Observer {
public:
void notify(Reservation* reservation) {
    cout << "Email notification sent to user " << reservation->getUser()->getUserName() << " for reservation id " << reservation->getReservationId() << endl;
}
};

class SMSNotiifer : public Observer {
public:
void notify(Reservation* reservation) {
    cout << "SMS notification sent to user " << reservation->getUser()->getUserName() << " for reservation id " << reservation->getReservationId() << endl;
}
};

#endif // NOTIFICATION_H
