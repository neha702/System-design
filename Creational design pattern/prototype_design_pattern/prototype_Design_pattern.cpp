#include "../../bitsStd.h"
using namespace std;

//A client is used to create clone here , and creating client takes prototype
//without creating client too clone can be created

class Shape {
public:
    virtual void draw() = 0;
    virtual Shape* clone() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Circle is drawn" << endl;
    }

    Shape* clone() {
        cout << "Clone is created" << endl;
        return new Circle();
    }
};

class ShapeClient {
Shape* shapePrototype;
public:
    ShapeClient(Shape* prototype) {
        this->shapePrototype = shapePrototype;
    }

    Shape* createShape(Shape* shapePrototype) {
        return shapePrototype->clone();
    }
};

int main() {
    Shape* prototype = new Circle();
    ShapeClient* client = new ShapeClient(prototype);
    Shape* clonedObj = client->createShape(prototype);
    clonedObj->draw();
    return 0;
}