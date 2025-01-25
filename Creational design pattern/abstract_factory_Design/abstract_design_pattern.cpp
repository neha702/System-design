//It uses a factory that creates either Tat or Hyundai factory that internally calls another factory that create car and bikes of this individual factories
//Three interfaces used one for factoryType, another for car and bike
#include "../../bitsStd.h"
#include "factoryType.h"
#include "vehicleType.h"

using namespace std;

class VehicleFactory {
public:
    static IFactory* createFactory(string factoryType) {
        IFactory* fact;

        if( factoryType == "Hyundai") {
           fact = new HyundaiFactory();
        }else if (factoryType=="Tata") {
           fact = new TataFactory();
        }

        return fact;
    }

};

int main() {
    string factoryType;
    string vehicleType;

    cin >> factoryType;

    IFactory* fact = VehicleFactory::createFactory(factoryType);

    ICar* car = fact->createCar();

    car->show();

    IBike* bike = fact->createBike();

    bike->show();

    return 0;
  
}