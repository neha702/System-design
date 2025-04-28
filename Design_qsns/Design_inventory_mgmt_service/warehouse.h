#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include<unordered_map>
#include "product.h"
#include <vector>
using namespace std;

class Warehouse {
    string location;
    int id;
    unordered_map<int , Product*>productMap; // map of id to product
public:
    Warehouse(int id , string location) {
        this->location = location;
        this->id = id;
    }

    int getId() {
        return id;
    }

    void addProduct(Product* p , int quantity) {
        int id = p->getId();
    
        //product exist in map
        if(productMap.find(id) != productMap.end()) {
            productMap[id]->addStock(quantity);
            cout << "Product " << p->getName() << " restocked with quantity " << quantity << endl;
        } else {
            // product not in map
            p->setQuantity(quantity);
            productMap[id] = p;
            cout << "Product " << p->getName() << " added to product map with quantity " << quantity << endl;
        }
    }

    Product* getProductById(int id) {
        return productMap[id];
    }

     bool removeProduct(Product* p , int quantity) {
        int id = p->getId();

        int currQuantity = p->getQuantity();

        if(productMap.find(id) ==  productMap.end()) {
            cout << "Product " << p->getName() <<  " doesn't exist to be removed" << endl;
            return false;
        } else if (currQuantity < quantity) {
            cout << "Product " << p->getName() <<  " doesn't have enough stock to be removed" << endl;
            return false;
        } else if (currQuantity == quantity) {
            productMap.erase(id);
            cout << "Product " << p->getName() <<  " removed from productmap since its quantity is zero" << endl;
        } else {
            productMap[id]->removeStock(quantity);
            cout << "Product " << p->getName() <<  " with quantity "  << quantity << " removed " << endl;
        }
        return true;
    }

    vector<Product*> getAllProducts() {
        vector<Product*>products;
        for(auto it : productMap) {
            products.push_back(it.second);
        }
        return products;
    }
};

#endif // WAREHOUSE_H