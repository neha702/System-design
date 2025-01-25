#include "../bitsStd.h"
using namespace std;

class Iimage {
public:
virtual void display() = 0;
};

class RealImage : public Iimage{
string fileName;
public:
RealImage(string filename) {
this->fileName = filename;
loadImgFromDisk();
}

void loadImgFromDisk() {
    cout << "Loading image " << fileName << " from disk" << endl;
}

void display() {
    cout << "Displaying image " << fileName << endl;
}
};

class ProxyImage : public Iimage{
string fileName;
RealImage* realImg;
public:

ProxyImage(string filename) {
this->fileName = filename;
}

void display() {
    if(realImg == nullptr) {
        this->realImg = new RealImage(fileName); // image is created and loaded
    }
    realImg->display();
}

};

int main() {
    //client code
    ProxyImage* proxyImage = new ProxyImage("img1.jpg");
    proxyImage->display(); //real image is loaded and displayed
    proxyImage->display(); //real image is already in data member , which is displayed
}