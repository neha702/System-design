#ifndef PAYMENT_FACTORY_H
#define PAYMENT_FACTORY_H

#include "payment.h"

class PaymentFactory{
public:
PaymentStrategy* getPaymentStrategyObj(string paymentType) {
    if(paymentType == "CREDIT_CARD") {
        return new CreditCard();
    } else if (paymentType == "CASH") {
        return new Cash();
    }
}
};

#endif