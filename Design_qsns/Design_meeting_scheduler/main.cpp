#include "../../bitsStd.h"
#include "meetingService.h"
#include "user.h"
using namespace std;

int main() {
    MeetingService* meetingServiceInstance = MeetingService::getMeetingServiceInstance();
    UserManager* userManagerInstance = meetingServiceInstance->getUserManagerInstance();

    User* u1 = new User("Alice" , "alice@gmail.com");
    User* u2 = new User("Neha" , "neha12@gmail.com");
    User* u3 = new User("Likha" , "likh13@gmail.com");
    User* u4 = new User("Rose" , "rose14@gmail.com");
    User* u5 = new User("Chandler" , "chand4@gmail.com");
    userManagerInstance->addUser(u1);
    userManagerInstance->addUser(u2);
    userManagerInstance->addUser(u3);
    userManagerInstance->addUser(u4);
    userManagerInstance->addUser(u5);

    vector<User*>attendees1;
    attendees1.push_back(u1);
    attendees1.push_back(u2);

    //meeting with u1 and u2 should be created
    int meetingId1 = meetingServiceInstance->createMeeting(u1 , 13 , 16 , "Intro to dance" , attendees1 , MeetingType::ONETOONE);
    
    //view meetings for u2
    meetingServiceInstance->viewMeetings(u2);

    //should not be created
    vector<User*>attendees2;
    attendees2.push_back(u2);
    attendees2.push_back(u3);
    int meetingId2 = meetingServiceInstance->createMeeting(u2 , 14 , 15 , "Intro to music" , attendees2 , MeetingType::GROUP);
    
    //should be created
    vector<User*>attendees3;
    attendees3.push_back(u4);
    attendees3.push_back(u5);
    int meetingId3 = meetingServiceInstance->createMeeting(u5 , 13 , 16 , "Intro to art" , attendees3 , MeetingType::ONETOONE);

    //u1 and u2 got unblocked
    meetingServiceInstance->removeMeeting(meetingId1);
    
    //meeting with u2 and u3 should be created now
    int meetingId4 = meetingServiceInstance->createMeeting(u2 , 13 , 16 , "Intro to music" , attendees2 , MeetingType::GROUP);

    meetingServiceInstance->viewMeetings(u2);
}