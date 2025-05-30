#ifndef MEETINGOBSERVER_H
#define MEETINGOBSERVER_H
#include "user.h"

class MeetingObserver {
public:
    void notifyAddition(User* u , string meeting) {
        cout << "User " << u->getUserName() << " is added to meeting " << meeting << endl;
    }

     void notifyRemoval(User* u, string meeting) {
        cout << "User " << u->getUserName() << " is removed from meeting " << meeting << endl;
    }
};



#endif // MEETINGOBSERVER_H