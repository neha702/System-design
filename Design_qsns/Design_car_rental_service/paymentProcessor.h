#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H
#include "paymentStrategy.h"

class PaymentProcessor {
    PaymentStrategy* paymentStrategy;
public:
    void setPaymentStrategy(PaymentStrategy* paymentStrategy) {
       this->paymentStrategy = paymentStrategy;
    }

    void processPayment(int amount) {
        paymentStrategy->pay(amount);
    }
};

#endif // PAYMENTPROCESSOR_H