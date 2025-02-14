#ifndef ERRORLOGPROCESSOR_H
#define ERRORLOGPROCESSOR_H

#include "logProcessor.h"
#include<string>
#include<iostream>
using namespace std;

// Your declarations here
class ErrorLogProcessor : public LogProcessor{
public:
void log(string message , long timestamp , int level , LoggingStrategy* logStrategy) {
    if(level == LogProcessor::errorLevel) {
       string logMessage = "[" + to_string(timestamp) + "]" + " [ERROR] " + message;
       logStrategy->write(logMessage);
    }
   else if(nextLogProcessor != nullptr) {
        nextLogProcessor->log(message , timestamp , level , logStrategy);
    }
}
};

#endif // ERRORLOGPROCESSOR_H