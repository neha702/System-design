#include "../bitsStd.h"
using namespace std;

class Request {
string priority;
public:
Request(string priorty) {
    this->priority = priorty;
}

string getPriority() {
    return priority;
}
};

class ILevelHandler {
public:
virtual void handleRequest(Request* request) = 0;
virtual void setNextHandler(ILevelHandler* nextLevelHandler) = 0;
};


class LevelOneHandler : public ILevelHandler{
ILevelHandler* nextHandler;
public:
void setNextHandler(ILevelHandler* nextHandler) {
    this->nextHandler = nextHandler;
}

void handleRequest(Request* request) {
    if(request->getPriority() == "BASIC") {
        cout << "Level one handled the request" << endl;
    } else if (nextHandler != nullptr) {
        nextHandler->handleRequest(request);
    }
}
};

class LevelTwoHandler : public ILevelHandler{
ILevelHandler* nextHandler;
public:
void setNextHandler(ILevelHandler* nextHandler) {
    this->nextHandler = nextHandler;
}

void handleRequest(Request* request) {
    if(request->getPriority() == "INTERMEDIATE") {
        cout << "Level two handled the request" << endl;
    } else if (nextHandler != nullptr) {
        nextHandler->handleRequest(request);
    }
}
};

class LevelThreeHandler : public ILevelHandler{
ILevelHandler* nextHandler;
public:
void setNextHandler(ILevelHandler* nextHandler) {
    this->nextHandler = nextHandler;
}

void handleRequest(Request* request) {
    if(request->getPriority() == "CRITICAL") {
        cout << "Level three handled the request" << endl;
    } else if (nextHandler != nullptr) {
        nextHandler->handleRequest(request);
    }
}
};


int main() {
ILevelHandler* levelOneHandler = new LevelOneHandler();
ILevelHandler* levelTwoHandler = new LevelTwoHandler();
ILevelHandler* levelThreeHandler = new LevelThreeHandler();

//form chain
levelOneHandler->setNextHandler(levelTwoHandler);
levelTwoHandler->setNextHandler(levelThreeHandler);

Request* request1 = new Request("BASIC");
Request* request2 = new Request("CRITICAL");

levelOneHandler->handleRequest(request1);
levelOneHandler->handleRequest(request2); // how would level one handler handle basic request, basically since one can't it is passed to two , and even two can't so passed to three

}