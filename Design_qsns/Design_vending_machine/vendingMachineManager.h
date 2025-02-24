#ifndef VENDINGMACHINEMANAGER_H
#define VENDINGMACHINEMANAGER_H
#include "vendingMachine.h"
using namespace std;

class VendingMachineManager {
public:
static int balance;
static unordered_map<int, Product*> itemIdToProductMap;

static unordered_map<int, Product*> getItemIdToProductMap() {
    return itemIdToProductMap;
}

static int getBalance() {
    return balance;
}

static void updateBalance(int value) {
    balance += value;
}

static void setProductToItemIdToProductMap(int productCode , Product* p) {
    itemIdToProductMap[productCode] = p;
}

void addProduct(int productCode , int quantity , int price) {
    Product* product = new Product(productCode , price , quantity);
    cout << "Product added of code " << productCode << " with quantity " << quantity << endl;
    unordered_map<int , Product*> itemIdToProductMap = getItemIdToProductMap();
    if(quantity == 0) {
        cout << "Can't add product since quantity is zero!" << endl;
        return;
    }
    setProductToItemIdToProductMap(productCode , product);
}

void stockUpProduct(int productCode , int quantity) {
    unordered_map<int , Product*> itemIdToProductMap = getItemIdToProductMap();
    Product* product = itemIdToProductMap[productCode];
     cout << "Product stocked up of code " << productCode << " with quantity " << quantity << endl;
    product->stockUpQuantity(quantity);
}

static Product* getProductByCode(int productCode) {
    if(itemIdToProductMap.find(productCode) != itemIdToProductMap.end()) {
        Product* product = itemIdToProductMap[productCode];

        if(product->getPrice() > getBalance()) {
            cout << "Insufficient balance to buy this product!" << endl;
            return nullptr; 
        }

        if(product->getQuantity()== 0) {
            itemIdToProductMap.erase(productCode);
        }

        product->decQuantity();

        return itemIdToProductMap[productCode];
    } else {
        cout << "Insufficent stock for this product with code " << productCode << endl;
        return nullptr;
    }
}
};
int VendingMachineManager::balance = 0;
unordered_map<int, Product*> VendingMachineManager::itemIdToProductMap;


#endif // VENDINGMACHINEMANAGER_H