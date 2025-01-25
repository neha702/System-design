#ifndef FACTORYTYPE_H
#define FACTORYTYPE_H
#include "vehicleType.h"

class IFactory {
public:
    virtual ICar* createCar() = 0;
    virtual IBike* createBike() = 0;
};

class HyundaiFactory : public IFactory {
public:
    ICar* createCar() {
        return new HyundaiCar();
    }

    IBike* createBike() {
        return new HyundaiBike();
    }
};

class TataFactory : public IFactory {
public:
    ICar* createCar() {
        return new TataCar();
    }

    IBike* createBike() {
        return new TataBike();
    }
};

#endif