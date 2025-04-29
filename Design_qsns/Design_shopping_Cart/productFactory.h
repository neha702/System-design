#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include <iostream>
#include "enums.h"
#include "product.h"
using namespace std;

class ProductFactory {
public:
    Product* createProduct(string name, int id ,double price ,int quantity,ProductCategory productCategory){
        switch(productCategory) {
            case 0 : return new ClothingProduct(name , quantity ,price , CLOTHING , id);
            case 1 : return new ElectronicsProduct(name ,quantity ,price , ELECTRONICS , id);
            case 2 : return new GroceryProduct(name , quantity ,price , GROCERY , id);
        }
    }
};

#endif // PRODUCTFACTORY_H