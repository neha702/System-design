#ifndef INVENTORYOBSERVER_H
#define INVENTORYOBSERVER_H
#include "product.h"
#include <vector>

class InventoryObserver {
public:
    virtual void notify(Product* p) = 0;
};

class SupplierObserver : public InventoryObserver {
    string supplierName;
    string email;
public:
    SupplierObserver(string name , string email) {
        this->supplierName = name;
        this->email = email;
    }
    void notify(Product* p) {
        cout << "Supplier " << supplierName << " has been notified about shortage of product name " << p->getName() << endl;
    }
};

class AdminsObserver : public InventoryObserver {
   vector<string>admins;
public:
    AdminsObserver(vector<string>admins) {
        this->admins = admins;
    }
    void notify(Product* p) {
       for(auto it : admins) {
        cout << "Admin " << it << " has been notified about shortage of product name " << p->getName() << endl;
       }
    }
};

#endif // INVENTORYOBSERVER_H