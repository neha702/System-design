#include "../bitsStd.h"
using namespace std;

// Interface for user required to make sure that the children for sure implement notify method (we used pure virtual function for that)
//Interfaces are pure abstract  classes
class ISubscriber {
    public:
     virtual void notify(string msg) = 0;

};

class User : public ISubscriber {

    private:
        int uid;

    public:

        User(int uuid) {
            this->uid = uuid;
        }

        void notify (string msg) {
            cout << msg << " ,received for user: " << uid <<endl;
        }
};


class Group {
    private:
     list<ISubscriber*>users; //its important to pass datatype as ISubscriber as otherwise for each child class type we need to take care of , so now it takes care of all child class type

    public:
        //Add in group
        void subscribe (ISubscriber* u1) {
            users.push_back(u1);
        }

        //Remove from group
        void unsubscribe (ISubscriber* u1) {
            users.remove(u1);
        }

        //Notify everyone in group
        void notifyUsers (string msg) {
            for (auto u1: users) {
                u1->notify(msg);
            }
        }
};


int main() {
    Group* g = new Group();

    User* u1 = new User(1);
    User* u2 = new User(2);

    g->subscribe(u1);
    g->subscribe(u2);

    g->notifyUsers("Hi new msg received");

    g->unsubscribe(u1);

    g->notifyUsers("Hi, check your mail");

    return 0;

}