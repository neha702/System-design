#ifndef USER_H
#define USER_H
#include <iostream>
#include "meeting.h"
#include "calendar.h"
#include <set>
using namespace std;

class User {
    string name;
    string emailid;
    set<Meeting*> meetings;
    Calendar* calendar;
public:
    User(string name , string emailid) {
        this->name = name;
        this->emailid = emailid;
        this->calendar = new Calendar();
    }

    set<Meeting*> getMeetings() {
        return meetings;
    }

    Calendar* getCalendar() {
        return calendar;
    }

    void addMeeting(long startTime , long endTime , Meeting* meeting){
        meetings.insert(meeting);
        calendar->addMeetingInCalendar(startTime , endTime , meeting);
    }

    void removeMeeting(Meeting* meeting) {
        long startTime = meeting->getStartTime();
        long endTime = meeting->getEndTime(); 
        meetings.erase(meeting);
        calendar->removeMeetingInCalendar(startTime , endTime);
     }

    void viewMeetings(){
        cout << "User " << name << " has following meetings scheduled: " << endl;
        for(auto meeting : meetings) {
            cout << meeting->getMeetingTitle() << " with start time: " << meeting->getStartTime() << " and end time: " << meeting->getEndTime() << endl;
        }
    }

    string getUserName() {
        return name;
    }

    bool isAvailable(long startTime , long endTime) {
        return calendar->isAvailable(startTime , endTime);
    }

};

#endif // USER_H