#ifndef RATELIMITERMANAGER_H
#define RATELIMITERMANAGER_H
#include <iostream>
#include "rateLimiterStrategy.h"
#include "rateLimiterFactory.h"
#include "../../bitsStd.h"
using namespace std;

class RateLimiterManager {
    int maxRequests;
    int windowTimestampSize;
    RateLimiterStrategy* rateLimitingStrategy;
public:
    static RateLimiterManager* rateLimitManger;
    static RateLimiterFactory* rateLimiterFactory;
    static mutex mtx;

    static RateLimiterManager* getInstance() {
      lock_guard<mutex> mutx(mtx);
      rateLimitManger = new RateLimiterManager();
      rateLimiterFactory = new RateLimiterFactory();
      return rateLimitManger;
    }

    void setRateLimitingStrategy(string strategy) {
        this->rateLimitingStrategy = rateLimiterFactory->createStrategy(strategy);
    }

    void setMaxRequests(int requests) {
        this->maxRequests = requests;
    }

    void setWindowTimestampSize(int windowSize) {
        this->windowTimestampSize = windowSize;
    }

    bool allowRequests(int clientId) {
        return rateLimitingStrategy->allowRequest(clientId , maxRequests , windowTimestampSize);
    }
};
RateLimiterFactory* RateLimiterManager::rateLimiterFactory = nullptr;
RateLimiterManager* RateLimiterManager::rateLimitManger = nullptr;
mutex RateLimiterManager::mtx;

#endif // RATELIMITERMANAGER_H