#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include<vector>
#include "product.h"
#include "couponDecorator.h"
using namespace std;

class ShoppingCart {
    vector<pair<Product* , int> >products;
public:
    void addToCart(Product* p , double discountPercentage , int quantity) {
        //apply coupon
       if(p->getQuantity() < quantity) {
         quantity = p->getQuantity();
         cout << "Quantity " << quantity << " of product " << p->getName() << " needs to be removed!" << endl;
       }
       Product* product = new TypeCouponDecorator(new DiscountCouponDecorator(discountPercentage , p));
       products.push_back({product , quantity});
       product->removeStock(quantity);
    }

    double getTotalPrice() {
        double totalPrice = 0;
        for(auto product : products) {
            totalPrice += ((product.first->getPrice())*product.second);
        }
        return totalPrice;
    }

    virtual ~ShoppingCart() {
        for(auto product : products) delete product.first;
    }
};

#endif // SHOPPINGCART_H