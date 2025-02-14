#include "../../bitsStd.h"
#include "errorLogProcessor.h"
#include "infoLogProcessor.h"
#include "logProcessor.h"
#include "logger.h"
#include "warningLogProcessor.h"
using namespace std;

int main() {
   Logger* logger = Logger::getLoggerInstance();
   logger->log("This is information",1234 , LogProcessor::infoLevel);

    logger->setLogTarget("file");
    logger->log("This is warning" , 1560 , LogProcessor::warningLevel);

    logger->setLogLevel(LogProcessor::errorLevel);
    logger->log("This is second warning" , 1562 , LogProcessor::warningLevel);
}