#ifndef COUPONDECORATOR_H
#define COUPONDECORATOR_H
#include "product.h"
#include "enums.h"
#include  <unordered_map>

class CouponDecorator : public Product {
protected:
    Product* p;
public:
CouponDecorator(Product* p) : Product(p->getId() , p->getName() ,p->getQuantity(), p->getPrice() , p->getProdCategory()) {
    this->p = p;
}
virtual ~CouponDecorator() {
    delete p;
}
};

class DiscountCouponDecorator : public CouponDecorator {
    double discountPercentage;
public:
    DiscountCouponDecorator(double discountPercentage , Product* p) : CouponDecorator(p){
        this->discountPercentage = discountPercentage;
    }

    double getPrice() {
        double price = p->getPrice();
        price = price - ((discountPercentage) / 100)*price;
        return price;
    }
};

class TypeCouponDecorator : public CouponDecorator {
public:
    unordered_map<ProductCategory , double>elligibleCategories = {{ELECTRONICS , 10} , {GROCERY , 15}};
    TypeCouponDecorator(Product* p) : CouponDecorator(p) {
    }

    double getPrice() {
        double price = p->getPrice();
        ProductCategory category = p->getProdCategory();

        if(elligibleCategories.find(category) != elligibleCategories.end()){
            price = price - ((elligibleCategories[category]) / 100)*price;
             cout << "Type coupon applied on product!" << endl;
            return price;
        } else {
            cout << "Product doesnt belong to elligible category for type coupon to be applied!" << endl;
            return price;
        }
    }
};

#endif // COUPONDECORATOR_H