#ifndef RATELIMITERSTRATEGY_H
#define RATELIMITERSTRATEGY_H
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class RateLimiterStrategy {
public:
    virtual bool allowRequest(int id , int maxRequests , int windowSize) = 0;
};

// two things to check if we can accomodate and if it really falls in this window
//each client have their own window by which i mean their own starting timestamps
class FixedWindowRateLimiterStrategy : public RateLimiterStrategy{
    unordered_map<int , int>startTimestamps;
    unordered_map<int ,int>requests;
public:
    bool allowRequest(int id ,int maxRequests , int windowSize) {
        int currTime = static_cast<int>(std::time(nullptr)); // seconds since epoch
        //new user
        if(startTimestamps.find(id) == startTimestamps.end()) {
            startTimestamps[id] = currTime;
            requests[id] = 0;
        }

        //if window is expired
        if(currTime - startTimestamps[id]  > windowSize) {
            startTimestamps[id] = currTime;
            requests[id] = 0;
        }

        cout << currTime << " " << startTimestamps[id] << " " << requests[id] << endl;

        //in current window can i add more requests
        if(requests[id] + 1 <= maxRequests) {
            requests[id]++;
            return true;
        }
        //cout << requests[id] << " " << currTime << " " << startTimestamps[id] << endl;
        return false;
    }
};

class SlidingWindowRateLimiterStrategy : public RateLimiterStrategy {
    unordered_map<int , queue<int> >requestTimestamps;  
public:
    bool allowRequest(int id, int maxRequests , int windowSize) {
       int currTime = static_cast<int>(std::time(nullptr)); // seconds since epoch

        queue<int> requestQueue = requestTimestamps[id];

        //if window is expired , remove requests before it
        while(!requestQueue.empty() && requestQueue .front() < currTime - windowSize) {
            requestQueue .pop();
        }

        requestTimestamps[id] = requestQueue;

        //in current window can i add more requests
        if(requestTimestamps[id].size() < maxRequests) { // size gives how many requests are there for this window
            requestTimestamps[id].push(currTime);
            return true;
        }
        return false; 
    }
};

#endif // RATELIMITERSTRATEGY_H