//Implement logger

#include "../bitsStd.h"
using namespace std;

class Logger {
    private:
    static Logger* loggerInstance;
    static mutex mtx;                      //Mutex to ensure thread safety
    static int instanceCount;
    Logger(){                              //constructor is made private
            instanceCount++;
            cout << "New instance created" << " " << instanceCount << endl;
    } 

    public:
        void printLog(string msg) {
            cout << msg << endl;
        }

        static Logger* getLogger() {       //static function is used to create a single object for this class
          //double checked locking
          if (loggerInstance == nullptr){  //need to lock only if loggerInstance is nullptr  otherwise return the loggerInstance only
                mtx.lock();
                if (loggerInstance == nullptr) {
                      loggerInstance = new Logger();
                 }
                mtx.unlock();
          } 
          
          return loggerInstance;
        }
};

//initialise static variables
int Logger::instanceCount = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

void userLogs1 () {
 Logger* logger1 = Logger::getLogger();
 logger1->printLog("First logger result");
}

void userLogs2 () {
 Logger* logger2 = Logger::getLogger();
 logger2->printLog("Second logger result");
}

int main() {
 
   thread t1(userLogs1);               //calls userLogs1 function
   thread t2(userLogs2);               //calls userLogs2 function
  
   t1.join();
   t2.join();
  
   return 0;
}