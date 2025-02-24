#ifndef DENOMINATION_H
#define DENOMINATION_H

class Denomination {
int price;
public:
Denomination(int price) {
    this->price = price;
}
int getPrice(){
    return price;
}
};

class Coin : public Denomination {
public:
Coin(int price) : Denomination(price) {}
};

class Note : public Denomination {
public:
Note(int price) : Denomination(price) {}
};

#endif // DENOMINATION_H