#ifndef MEETINGSERVICE_H
#define MEETINGSERVICE_H
#include "user.h"
#include "userManager.h"
#include "meetingObserver.h"

class MeetingService {
    static MeetingService* meetingSvcInstance;
    static UserManager* userManagerInstance;
    static mutex mtx;
    static int meetingId;
    unordered_map<int , Meeting*> meetingMap; //meetingId to meeting map
    MeetingObserver meetingObserver; //observer to notify about meeting changes
    vector<User*>users;
public:
    static MeetingService* getMeetingServiceInstance() {
        if(meetingSvcInstance == nullptr) {
            lock_guard<mutex> meetingMutex(mtx);
            meetingSvcInstance = new MeetingService();
            userManagerInstance = new UserManager();
        }
        return meetingSvcInstance;
    }

    int createMeeting(User* u , long startTime , long endTime ,string title, vector<User*>attendees ,MeetingType meetingType) {
        set<User*> usersSet = userManagerInstance->getUserSet();
        //validation => if user exist or not available to be added in meeting
        for(auto attendee : attendees) {
            if(usersSet.find(attendee) == usersSet.end() || !attendee->isAvailable(startTime , endTime)) {
                cout << "User doesnt exist/ not available to create meeting!" << endl;
                return -1;
            }
        }

        meetingId++;
        //single meeting created for all attendees
        Meeting* newMeeting = new Meeting(startTime , endTime , title , meetingId ,attendees , u , meetingType);
        //meeting to be added for all attendees in calendar
        for(auto attendee : attendees) {
         attendee->addMeeting(startTime , endTime , newMeeting);
         meetingObserver.notifyAddition(attendee , newMeeting->getTitle()); //notify each attendee about the meeting
        }
    
        meetingMap[meetingId] = newMeeting;
        cout << "New meeting " << title << " is added!" << endl;
        return meetingId;
    }

    UserManager* getUserManagerInstance() {
        return userManagerInstance;
    }

    void removeMeeting(int meeting_id) {
        Meeting* meeting = meetingMap[meeting_id];
        set<User*> usersSet = userManagerInstance->getUserSet();
        vector<User*> attendees = meeting->getAttendees();

        //remove meeting for all attendees
        for(auto attendee : attendees) {
            attendee->removeMeeting(meeting);
            meetingObserver.notifyRemoval(attendee ,  meeting->getTitle()); //notify each attendee about the meeting
        }

        meetingMap.erase(meeting_id);
        cout << "Meeting " << meeting->getTitle() << " is removed!" << endl;
    }

    void viewMeetings(User* u) {
        u->viewMeetings();
    }
};
int MeetingService::meetingId = 0;
MeetingService* MeetingService::meetingSvcInstance = nullptr;
UserManager* MeetingService::userManagerInstance = nullptr;
mutex MeetingService::mtx;

#endif // MEETINGSERVICE_H