#ifndef LOGPROCESSOR_H
#define LOGPROCESSOR_H
#include <iostream>
#include "loggingStrategy.h"
using namespace std;

class LogProcessor {
protected:
LogProcessor* nextLogProcessor;
public:
static int infoLevel;
static int warningLevel;
static int errorLevel;

void setNextLevelProcessor(LogProcessor* nextLogProcessor) {
    this->nextLogProcessor = nextLogProcessor;
}
virtual void log(string message , long timestamp , int level , LoggingStrategy* logStrategy) = 0;
};

int LogProcessor::infoLevel = 1;
int LogProcessor::warningLevel = 2;
int LogProcessor::errorLevel = 3;

#endif // LOGPROCESSOR_H