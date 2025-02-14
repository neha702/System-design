#ifndef LOGGER_H
#define LOGGER_H
#include <mutex>
#include "logManager.h"
#include "logProcessor.h"
#include "loggingStrategy.h"

class Logger {
public:
static int logLevel;
static Logger* loggerInstance;
static mutex mtx;
static LoggingStrategy* logStrategy;
static LogProcessor* logProcessorObj;
static Logger* getLoggerInstance() {
    if(loggerInstance == nullptr) {
        mtx.lock();
        if(loggerInstance == nullptr) {
            loggerInstance = new Logger();
            cout << "Logger instance created" << endl;
            logProcessorObj = LogManager::createLoggerChain();
            cout << "Logger chain created" << endl;
        }
        mtx.unlock();
    }
    return loggerInstance;
}

void setLogLevel(int level) {
    logLevel = level;
}

int getLogLevel() {
    return logLevel;
}

void log(string message , long timestamp , int level) {
    if(logProcessorObj != nullptr && level >= logLevel)
        logProcessorObj->log(message , timestamp , level , logStrategy);
    else cout << "Logging at this level is not allowed" << endl;
}

void setLogTarget(string target) {
    if (target == "console") {
        logStrategy = new LogByConsole();
    } else if (target == "file") {
        logStrategy = new LogByFile();
    } else if (target == "database") {
        logStrategy = new LogByDatabase();
    } else {
        cout << "Unknown log target: " << target << endl;
    }
}
};

Logger* Logger::loggerInstance = nullptr;
LogProcessor* Logger::logProcessorObj = nullptr;
int Logger::logLevel = 1;
mutex Logger::mtx;
LoggingStrategy* Logger::logStrategy = new LogByConsole();

#endif // LOGGER_H