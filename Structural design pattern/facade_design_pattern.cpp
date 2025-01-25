#include "../bitsStd.h"
using namespace std;

//subsystem 1
class Engine {
public:
void start() {
    cout << "Engine started!" << endl;
}

void stop() {
    cout << "Engine stopped!" << endl;
}
};

//subsystem 2
class Light {
public:
void turnOn() {
    cout << "Lights turned on!" << endl;
}

void turnOff() {
    cout << "Lights turned off!" << endl;
}
};

//facade
class Car {
Engine engine;
Light light;
public:
void startCar() {
    engine.start();
    light.turnOn();
}

void stopCar() {
    light.turnOff();
    engine.stop();
}
};

int main() {
Car* car = new Car();
car->startCar();
car->stopCar();
}