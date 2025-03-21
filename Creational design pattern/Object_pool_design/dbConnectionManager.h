#ifndef DBCONNECTIONMANAGER_H
#define DBCONNECTIONMANAGER_H
#include <vector>
using namespace std;
#include <iostream>
#include "dbConnection.h"

class DBConnectionManager {
vector<DBConnection*> freeConnections;
vector<DBConnection*> inUseConnections;
int maxPoolSize = 6;
int initialPoolSize = 3;
mutex poolMutex;
static DBConnectionManager* dbConnectionManagerInstance;
public:
static mutex dbInstanceMutex;
DBConnectionManager() {
    for(int i = 0 ; i < initialPoolSize ; i++) {
        DBConnection* connection = new DBConnection();
        freeConnections.push_back(connection);
    }
}

static DBConnectionManager* getInstance() {
    if(dbConnectionManagerInstance == nullptr) {
        lock_guard<mutex>lock(dbInstanceMutex);
        if(dbConnectionManagerInstance == nullptr) {
            dbConnectionManagerInstance = new DBConnectionManager();
        }
    }
    return dbConnectionManagerInstance;
}

DBConnection* getConnection() {
    lock_guard<mutex>lock(poolMutex);

    if(freeConnections.empty() && inUseConnections.size() < maxPoolSize) {
        freeConnections.push_back(new DBConnection());
    } else if (freeConnections.empty() && inUseConnections.size() >= maxPoolSize) {
        cout << "All connections being used!" << endl;
        return nullptr;
    }

    DBConnection* connection = freeConnections.at(0);
    freeConnections.erase(freeConnections.begin() + 0);
    inUseConnections.push_back(connection);
    return connection;
}

void releaseConnection(DBConnection* connection) {
    bool connectionFound = false;
    for(int i = 0; i < inUseConnections.size() ; i++) {
        if(inUseConnections[i] == connection) {
            cout << "Connection is released!" << endl;
            connectionFound = true;
            inUseConnections.erase(inUseConnections.begin() + i);
            freeConnections.push_back(connection);
        }
    }

    if(!connectionFound) {
        cout << " Connection not found so couldn't be released" << endl;
    }
}
};

DBConnectionManager* DBConnectionManager::dbConnectionManagerInstance = nullptr;
mutex DBConnectionManager::dbInstanceMutex;

#endif // DBCONNECTIONMANAGER_H