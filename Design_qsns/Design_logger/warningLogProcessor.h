#ifndef WARNINGLOGPROCESSOR_H
#define WARNINGLOGPROCESSOR_H

#include "logProcessor.h"
#include<string>
#include<iostream>
using namespace std;

// Your declarations here
class WarningLogProcessor : public LogProcessor{
public:
void log(string message , long timestamp , int level , LoggingStrategy* logStrategy) {
    if(level == LogProcessor::warningLevel) {
       string logMessage = "[" +  to_string(timestamp) + " [WARNING] " + message;
       logStrategy->write(logMessage);
    }
    else if(nextLogProcessor != nullptr) {
        nextLogProcessor->log(message , timestamp , level , logStrategy);
    }
}
};

#endif // WARNINGLOGPROCESSOR_H