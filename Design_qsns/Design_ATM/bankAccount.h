#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
int bankAccountNum;
int ifsc_code;
int balance = 0;
public:
BankAccount(int bankAccountNum , int ifsc_code , int balance) {
    this->bankAccountNum = bankAccountNum;
    this->ifsc_code = ifsc_code;
    this->balance = balance;
}

int getBalance() {
    return balance;
}

int setBalance(int value) {
    balance = value;
}
};

#endif // BANKACCOUNT_H