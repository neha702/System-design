//  You avoid tight coupling between concrete products and client code.
//  Single Responsibility Principle. You can extract the product creation code into one place, making the code easier to support.
//  Open/Closed Principle. You can introduce new variants of products without breaking existing client code
#include "../bitsStd.h"
using namespace std;

class Vehicle {
    public:
        virtual void createObject() = 0;
};

class Car : public Vehicle {
   public:
        void createObject() {
            cout << "Creating a car" <<endl;
        }
};

class Bike : public Vehicle{
   public:
        void createObject() {
            cout << "Creating a bike" <<endl;
        }
};

class VehicleFactory {
    public:
        static Vehicle* getVehicle(string vehicleType) { //In static function we need to  define data member in static function
            Vehicle* vehicle;
            if(vehicleType == "Bike") {
                vehicle = new Bike();
             } else if(vehicleType == "Car") {
                 vehicle = new Car();
             }
         return vehicle;
        }

};

int main() {
    string vehicleType;

    cin >> vehicleType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
   
    vehicle -> createObject();

    return 0;
}