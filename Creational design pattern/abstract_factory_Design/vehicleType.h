#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H
using namespace std;

class ICar{
public:
    virtual void show()=0;
};

class IBike{
public:
    virtual void show()=0;
};

class HyundaiCar : public ICar {
public:
    void show() {
        cout << "Presenting you new Hyundai car." << endl;
    }
};

class HyundaiBike: public IBike {
public:
    void show() {
        cout << "Presenting you new Hyundai bike." << endl;
    }
};

class TataCar : public ICar {
public:
    void show() {
        cout << "Presenting you new Tata car." << endl;
    }
};

class TataBike : public IBike {
public:
    void show() {
        cout << "Presenting you new Tata bike." << endl;
    }
};

#endif