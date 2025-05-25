#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <set>
#include "user.h"
using namespace std;

class UserManager {
    set<User*>users;
public:
    void addUser(User* u) {
        users.insert(u);
        cout << "User " << u->getUserName() << " is added!" <<endl;
    }

    void removeUser(User* u) {
        users.erase(u);
        cout << "User " << u->getUserName() << " is removed!" <<endl;
    }

    set<User*> getUserSet() {
        return users;
    }
};

#endif // USERMANAGER_H