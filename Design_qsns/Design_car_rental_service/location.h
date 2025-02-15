#ifndef LOCATION_H
#define LOCATION_H
#include <string>
using namespace std;

class Location {
string city;
long pincode;
public:
Location(string city , long pincode) {
    this->city = city;
    this->pincode = pincode;
}

string getCity() {
    return city;
}
};

#endif // LOCATION_H