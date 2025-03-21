#include "../../bitsStd.h"
#include "dbConnectionManager.h"
#include "dbConnection.h"
using namespace std;

int main() {
    DBConnectionManager* dbConnectionManager = DBConnectionManager::getInstance();
    DBConnection* dbConnection1 = dbConnectionManager->getConnection();
    DBConnection* dbConnection2 = dbConnectionManager->getConnection();
    DBConnection* dbConnection3 = dbConnectionManager->getConnection();
    DBConnection* dbConnection4 = dbConnectionManager->getConnection();
    DBConnection* dbConnection5 = dbConnectionManager->getConnection();
    DBConnection* dbConnection6 = dbConnectionManager->getConnection();
    dbConnectionManager->getConnection();
    dbConnectionManager->releaseConnection(dbConnection6);
    dbConnectionManager->getConnection();
}
