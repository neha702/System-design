#include "../bitsStd.h"
using namespace std;

class Color {
public:
virtual void fill() = 0;
};

class Red : public Color {
public:
void fill() {
    cout << " in Red" << endl;
}
};

class Yellow : public Color {
public:
void fill() {
    cout << " in yellow" << endl;
}
};

class Shape {
Color* colorImplementer;
public:

// Shape(Color* colorImp) {
//     this->colorImplementer = colorImp;
// }

virtual void draw() = 0;
};

class Circle : public Shape {
protected:
 Color* colorImplementer;
public:
Circle (Color* colorImp) {
    this->colorImplementer = colorImp;
}
void draw() {
    cout << "Draw a circle";
    colorImplementer->fill();
}
};

class Rectangle : public Shape {
protected:
Color* colorImplementer;
public:
Rectangle (Color* colorImp) {
    this->colorImplementer = colorImp;
}
void draw() {
    cout << "Draw a rectangle";
    colorImplementer->fill();
}
};



int main() {
    Shape* redCircle = new Circle(new Red());
    redCircle->draw();
    Shape* yellowRectangle = new Rectangle(new Yellow());
    yellowRectangle->draw();
}