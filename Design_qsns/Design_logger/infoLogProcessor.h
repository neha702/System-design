#ifndef INFOLOGPROCESSOR_H
#define INFOLOGPROCESSOR_H
#include "logProcessor.h"
#include<string>
#include<iostream>
using namespace std;

// Your declarations here
class InfoLogProcessor : public LogProcessor{
public:
void log(string message , long timestamp , int level , LoggingStrategy* logStrategy) {
    if(level == LogProcessor::infoLevel) {
        string logMessage = "[" + to_string(timestamp) + "]" + " [INFO] " + message;
        logStrategy->write(logMessage);
          
    }
    else if(nextLogProcessor != nullptr) {
        nextLogProcessor->log(message , timestamp , level , logStrategy);
    }
}
};

#endif // INFOLOGPROCESSOR_H