#ifndef INVENTORYSERVICE_H
#define INVENTORYSERVICE_H
#include<iostream>
#include <set>
#include "warehouse.h"
#include "replenishmentStrategy.h"
#include "productFactory.h"
#include "inventoryObserver.h"
using namespace std;

class InventoryService {
    set<Warehouse*> warehouses;
    vector<InventoryObserver*> inventoryObservers;
public:
    static ProductFactory* productFactory;
    static InventoryService* instance;
    static ReplenishmentStrategy* replenishmentStrategy;
    static mutex mtx;

    static InventoryService* getInstance() {
        if(instance == nullptr) {
            mtx.lock();
            if(instance == nullptr) {
                instance = new InventoryService();
                productFactory = new ProductFactory();
                replenishmentStrategy =  new ReorderPointStrategy();
                cout << "Inventory service and product factory created , replenishment strategy set!" << endl;
            }
            mtx.unlock();
        }
        return instance;
    } 

    bool addWarehouse(Warehouse* wh) {
        if(warehouses.find(wh) == warehouses.end()) {
             warehouses.insert(wh);
             cout << "Warehouse with id " << wh->getId() << " is added!" << endl;
             return true;
        }
        cout << "Warehouse with " << wh->getId() << " could not be added!" << endl;
        return false;
    }

    bool removeWarehouse(Warehouse* wh) {
        if(warehouses.find(wh) == warehouses.end()) {
            cout << "Warehouse with " << wh->getId() << " removed!" << endl;
             return false;
        }
        cout << "Warehouse with " << wh->getId() << " not found so couldnt be removed!" << endl;
        warehouses.erase(wh);
    }

    void checkInventory() {
        cout << "Checking inventory..." << endl;
        for(auto warehouse : warehouses) {
            for(auto product : warehouse->getAllProducts()) {
                if(replenishmentStrategy->checkForReplenish(product)) {
                    notifyObservers(product);
                    replenishmentStrategy->replenish(product);
                    cout << "Product " << product->getName() << " could be replenished!" << endl;
                } else {
                    cout << "Product " << product->getName() << " available so couldnt be replenished!" << endl;
                }
            }
        }
    }

    Product* getProductById(int id) {
        for(auto wh : warehouses) {
            if(wh->getProductById(id) != nullptr) return wh->getProductById(id);
        }
    }

    void checkProductForReplenish(int id) {
        Product* p = getProductById(id);

        if(p != nullptr) {
            if(replenishmentStrategy->checkForReplenish(p)) {
                notifyObservers(p);
                replenishmentStrategy->replenish(p);
                cout << "Product " << p->getName() << " was having quantity less than threshold so replenished" << endl;
            } else cout << "Product " << p->getName() << " was already having quantity more than threshold so not replenished" << endl;
        } else {
            cout << "Product with id " << id << " could not be found!" << endl; 
        }
    }

    void notifyObservers(Product* p) {
        for(auto obs : inventoryObservers) {
            obs->notify(p);
        }
    }

    ProductFactory* getProductFactory() {
        return productFactory;
    }
};
ProductFactory* InventoryService::productFactory = nullptr;
InventoryService* InventoryService::instance = nullptr;
ReplenishmentStrategy* InventoryService::replenishmentStrategy = nullptr;
mutex InventoryService::mtx;

#endif // INVENTORYSERVICE_H