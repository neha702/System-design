#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
int num;
string type;
public:
Vehicle(int num , string type) {
    this->num = num;
    this->type = type;
     cout << "Vehicle " << num <<" created!" << endl;
}

string getVehicleType() {
    return type;
}
};

#endif