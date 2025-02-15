#ifndef PAYMENT_H
#define PAYMENT_H
#include<iostream>
using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0; 
};

class PayByDebitCard : public PaymentStrategy {
public:
    void pay(int amount) {
        cout << "Payment made by debit card of amount " << amount << endl;
    }
};

class PayByUPI : public PaymentStrategy {
public:
    void pay(int amount) {
        cout << "Payment made by UPI of amount " << amount << endl;
    }
};
#endif // PAYMENT_H