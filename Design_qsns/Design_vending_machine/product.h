#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
int productCode;
int price;
int quantity;
public:
Product(int productCode , int price , int quantity) {
    this->productCode = productCode;
    this->price = price;
    this->quantity = quantity;
}

int getPrice() {
    return price;
}

void decQuantity() {
    quantity--;
}

int getQuantity() {
    return quantity;
}

void stockUpQuantity(int quantity) {
    this->quantity += quantity;
}
};

#endif // PRODUCT_H