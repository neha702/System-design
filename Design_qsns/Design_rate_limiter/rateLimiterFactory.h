#ifndef RATELIMITERFACTORY_H
#define RATELIMITERFACTORY_H
#include "rateLimiterStrategy.h"
#include <iostream>
using namespace std;

class RateLimiterFactory {
public:
    RateLimiterStrategy* createStrategy(string strategy_str) {
        if(strategy_str == "FIXED") {
            return new FixedWindowRateLimiterStrategy();
        } else if (strategy_str == "ROLLING") {
            return new SlidingWindowRateLimiterStrategy();
        } else return nullptr;
    }
};

#endif // RATELIMITERFACTORY_H