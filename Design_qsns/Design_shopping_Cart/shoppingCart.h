#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include<vector>
#include "product.h"
#include "couponDecorator.h"
using namespace std;

class ShoppingCart {
    vector<Product*>products;
public:
    void addToCart(Product* p , double discountPercentage) {
        //apply coupon
       Product* product = new TypeCouponDecorator(new DiscountCouponDecorator(discountPercentage , p));
       products.push_back(product);
    }

    double getTotalPrice() {
        double totalPrice = 0;
        for(auto product : products) {
            totalPrice += (product->getPrice());
        }
        return totalPrice;
    }

    virtual ~ShoppingCart() {
        for(auto product : products) delete product;
    }
};

#endif // SHOPPINGCART_H