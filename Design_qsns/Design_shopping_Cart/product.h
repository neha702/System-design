#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include "enums.h"
using namespace std;

class Product {
protected:
    string name;
    int quantity;
    double price;
    ProductCategory productCategory;
    int id;
public:
    Product(int id , string name , int quantity , double price, ProductCategory productCategory) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->id = id;
        this->productCategory = productCategory;
    }
   
    virtual double getPrice() = 0;

    void removeStock(int quantity) {
        this->quantity = this->quantity - quantity;
    }
    
    int getId() {
        return id;
    }

    int getQuantity() {
        return quantity;
    }

    string getName() {
        return name;
    }

    ProductCategory getProdCategory() {
        return productCategory;
    }
};

class ElectronicsProduct : public Product{
public:
    ElectronicsProduct(string name , int quantity , double price, ProductCategory productCategory , int id) : Product(id , name , quantity , price , ELECTRONICS ) {} 
    double getPrice() {
        return price;
    }
};

class GroceryProduct : public Product{
public:
    GroceryProduct(string name , int quantity , double price, ProductCategory productCategory , int id) : Product(id , name , quantity , price , GROCERY) {}  
    double getPrice() {
        return price;
    }
};

class ClothingProduct : public Product{
public:
    ClothingProduct(string name , int quantity , double price, ProductCategory productCategory , int id) : Product(id , name , quantity , price , CLOTHING) {} 
    double getPrice() {
        return price;
    }
};

#endif // PRODUCT_H