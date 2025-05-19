#include "../../bitsStd.h"
#include "rateLimiterManager.h"
#include <chrono>
#include <thread>
using namespace std;

int main() {
    RateLimiterManager* rateLimiterManager = RateLimiterManager::getInstance();
    rateLimiterManager->setMaxRequests(3);
    rateLimiterManager->setWindowTimestampSize(6);
    rateLimiterManager->setRateLimitingStrategy("ROLLING");

    for(int i = 0 ; i < 12 ; i++) {
        if(rateLimiterManager->allowRequests(0)) {
            cout << " Request id " << i << " is processed for clientId " << 0 << endl;
        } else {
            cout << " Request id " << i << " is dropped for clientId " << 0 << endl;
        }
         std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}