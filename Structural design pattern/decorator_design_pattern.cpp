#include "../bitsStd.h"
using namespace std;

//when parent constructor already do work of child constructor, in child constructor call parent constructor indeed , 
//and have one instance to be initialised in parent and make it protected to be accessed by children class
//this pattern helps to avoid class explosion that may happen due to a lot of combinations

class Coffee{ //component interface
public:
virtual int getCost() = 0;
};

class PlainCofee : public Coffee { //concrete component
public:
int getCost() {
    return 10;
}
};

class CoffeeDecorator : public Coffee { //decorator interface => decorator has a base coffee (aggregation or composition)
protected:
 Coffee* BaseCoffee;
public:
CoffeeDecorator(Coffee* bCoffee) {
    BaseCoffee = bCoffee;
}

virtual int getCost() = 0;
};

class SugarCoffeeDecorator : public CoffeeDecorator{ //concrete decorator class
public:
SugarCoffeeDecorator(Coffee* bCoffee) :CoffeeDecorator(bCoffee){
}

int getCost() {
    return BaseCoffee->getCost() + 10;
}
};

class MilkCoffeeDecorator : public CoffeeDecorator { //concrete decorator class
public:
MilkCoffeeDecorator(Coffee* bCoffee): CoffeeDecorator(bCoffee) {
}

int getCost() {
    return BaseCoffee->getCost() + 20;
}
};

int main() {
Coffee* plainCoffee = new PlainCofee();
cout << plainCoffee->getCost() << endl; // 10

//prepare sugar coffee
Coffee* sugarCoffee = new SugarCoffeeDecorator(plainCoffee); // decorate plain coffee with sugar decorator
cout << sugarCoffee->getCost() << endl;  //20

//prepare milk sugar coffee
Coffee* sugarMilkCoffee = new MilkCoffeeDecorator(sugarCoffee); // decorate sugar coffee with milk coffee
cout << sugarMilkCoffee->getCost() << endl; //40
}