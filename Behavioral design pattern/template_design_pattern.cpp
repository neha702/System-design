#include "../bitsStd.h"
using namespace std;

class IPayment {
public:
    virtual void validateRequest() = 0;
    virtual void debitPayment() = 0;
    virtual void confirmPayment() = 0;
    void sendPayment() {
        validateRequest();
        debitPayment();
        confirmPayment();
    }
};


class PayToFriend : public IPayment {
public :
void validateRequest() {
    cout << "Validate the request for sending payment to friend" << endl;
}

void debitPayment() {
    cout << "Debit the pay for sending payment to friend" << endl;
}

void confirmPayment() {
    cout << "Confirm the pay for sending payment to friend" << endl;
}
};

class PayToMerchant : public IPayment {
public :
void validateRequest() {
    cout << "Validate the request for sending payment to merchant" << endl;
}

void debitPayment() {
    cout << "Debit the pay for sending payment to merchant" << endl;
}

void confirmPayment() {
    cout << "Confirm the pay for sending payment to merchant" << endl;
}
};


int main() {
IPayment* payToFriendObj =  new PayToFriend();
payToFriendObj->sendPayment();

IPayment* payToMerchantObj =  new PayToMerchant();
payToMerchantObj->sendPayment();
}