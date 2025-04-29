#include "../../bitsStd.h"
#include "shoppingCart.h"
#include "product.h"
#include "productFactory.h"
using namespace std;
//consider discount coupons available for all products just needs to be applied , and discountPercentage needs to be provided and for type coupon decorator, there is map of product type to discount, so if product type already in map then that much discount is provided

int main() {
    ShoppingCart* shoppingCart = new ShoppingCart();
    ProductFactory* productFactory = new ProductFactory();
    
    Product* p1 = productFactory->createProduct("ExtBoard1" , 1 , 12.0 , 5 , ELECTRONICS);
    Product* p2 = productFactory->createProduct("Veggy1" , 2 , 2.0 , 2 , GROCERY);
    Product* p3 = productFactory->createProduct("Pant1" , 3 , 15.0 , 3 , CLOTHING);

    shoppingCart->addToCart(p1 , 10);
    shoppingCart->addToCart(p3 , 5);
    double value = shoppingCart->getTotalPrice();
    cout << "Shopping cart has cumulative value of " << value << endl;
}