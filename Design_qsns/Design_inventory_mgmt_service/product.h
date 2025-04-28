#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include "enums.h"
using namespace std;

class Product {
    string name;
    int id;
    int price;
    int quantity;
    int threshold;
    ProductCategory productCategory;
public:
    Product(string name, int id ,int price ,ProductCategory productCategory , int threshold) {
        this->name= name;
        this->id = id;
        this->price = price;
        this->productCategory = productCategory;
        this->threshold = threshold;
    }

    int getId() {
        return id;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void addStock(int quantity) {
        this->quantity = this->quantity + quantity;
    }

    void removeStock(int quantity) {
         this->quantity = this->quantity - quantity;
    }

    string getName() {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    int getThreshold() {
        return threshold;
    }
};

class ElectronicsProduct : public Product {
    string brand;
    int warrantyPeriod; // in months
public:
    ElectronicsProduct(string name, int id ,int price ,ProductCategory productCategory , int threshold) : Product(name , id , price ,ELECTRONICS , threshold) {}
};

class GroceryProduct : public Product {
    string brand;
    long expiryDate; 
public:
    GroceryProduct(string name, int id ,int price ,ProductCategory productCategory, int threshold) : Product(name , id , price ,GROCERY , threshold){}
};

class ClothingProduct : public Product {
    int size;
    string color; 
public:
    ClothingProduct(string name, int id ,int price ,ProductCategory productCategory ,int threshold) : Product(name , id , price , CLOTHING , threshold) {}
};

#endif // PRODUCT_H