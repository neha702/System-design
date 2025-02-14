#ifndef LOGGINGSTRATEGY_H
#define LOGGINGSTRATEGY_H
#include <string>
using namespace std;

class LoggingStrategy {
public:
    virtual void write(string message) = 0;
};

class LogByFile : public LoggingStrategy {
public:
    void write(string message) {
        cout << "[FILE]: " << message << endl;
    }
};

class LogByDatabase : public LoggingStrategy {
public:
    void write(string message) {
        cout << "[DB]: " << message << endl;
    }
};

class LogByConsole : public LoggingStrategy {
public:
    void write(string message) {
        cout << "[CONSOLE]: " << message << endl;
    }
};
#endif // LOGGINGSTRATEGY_H
