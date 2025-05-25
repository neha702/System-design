#ifndef CALENDAR_H
#define CALENDAR_H
#include <unordered_map>
#include "meeting.h"

class Calendar {
    unordered_map<long , Meeting*>meetingMap;
public:
    bool isAvailable(long startTime , long endTime) {
        //check if user is available between start and end time => meeting doesnt exist in both on start or end time
        bool ifAvailable = true;
        for(int i = startTime; i <= endTime; i++) {
            if(meetingMap.find(i) != meetingMap.end()) { // meeting exist in range
                ifAvailable = false;
                break;
            }
        }
        return ifAvailable;
    }

    vector<Meeting*> getMeetingsInTimeRange(long startTime , long endTime) {
        //get meetings in time range
    }

    void addMeetingInCalendar(long startTime , long endTime , Meeting* meeting) {
        for(int i = startTime ; i <= endTime ; i++) {
            meetingMap[i] = meeting;
        }
    }

    void removeMeetingInCalendar(long startTime , long endTime) {
        for(int i = startTime ; i <= endTime ; i++) {
            meetingMap.erase(i);
        }
    }
};

#endif // CALENDAR_H