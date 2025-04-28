#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include <iostream>
#include "enums.h"
#include "product.h"
using namespace std;

class ProductFactory {
public:
    Product* createProduct(string name, int id ,int price ,ProductCategory productCategory , int threshold){
        switch(productCategory) {
            case 0 : return new ClothingProduct(name , id , price , CLOTHING , threshold);
            case 1 : return new ElectronicsProduct(name , id , price , ELECTRONICS , threshold);
            case 2 : return new GroceryProduct(name , id , price , GROCERY , threshold);
        }
    }
};

#endif // PRODUCTFACTORY_H