#ifndef PAYMENT_H
#define PAYMENT_H

class PaymentStrategy {
public:
virtual void pay() = 0;
};

class CreditCard : public PaymentStrategy {
public:
void pay() {
    cout << "Payment made by credit card of amount" <<  endl;
}
};

class Cash : public PaymentStrategy {
public:
void pay() {
    cout << "Payment made by cash" << endl;
}
};


class Payment {
PaymentStrategy* paymentStrategy;
public:
void performPayment(int price , PaymentStrategy* paymentStrategy) {
    cout << "Payment to be made of " << price << endl;
    paymentStrategy->pay();
}
};

#endif