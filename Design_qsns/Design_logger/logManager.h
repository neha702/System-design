#ifndef LOGMANAGER_H
#define LOGMANAGER_H
#include "logProcessor.h"
#include "infoLogProcessor.h"
#include "warningLogProcessor.h"
#include "errorLogProcessor.h"

class LogManager {
public:
static LogProcessor* createLoggerChain() {
LogProcessor* infoLogProcessor = new InfoLogProcessor();
LogProcessor* warningLogProcessor = new WarningLogProcessor();
LogProcessor* errorLogProcessor = new ErrorLogProcessor();
infoLogProcessor->setNextLevelProcessor(warningLogProcessor);
warningLogProcessor->setNextLevelProcessor(errorLogProcessor);
return infoLogProcessor;
}
};

#endif