#ifndef MEETING_H
#define MEETING_H
#include <iostream>
#include <vector>
#include "enums.h"
using namespace std;

class User;

class Meeting {
    long startTime;
    long endTime;
    string title;
    int meetingId;
    vector<User*>attendees;
    User* creator;
    MeetingType meetingType;
public:
    Meeting(long startTime , long endTime , string title , int meetingId , vector<User*>attendees , User* creator , MeetingType meetingType) {
        this->meetingId = meetingId;
        this->startTime =  startTime;
        this->endTime = endTime;
        this->title = title;
        this->attendees = attendees;
        this->creator = creator;
        this->meetingType = meetingType;
    }

    string getTitle() {
        return title;
    }

    vector<User*> getAttendees() {
        return attendees;
    }

    long getStartTime() {
        return startTime;
    }

    long getEndTime() {
        return endTime;
    }

    string getMeetingTitle() {
        return title;
    }

};

#endif // MEETING_H