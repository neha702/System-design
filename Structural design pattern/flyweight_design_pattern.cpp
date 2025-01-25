#include "../bitsStd.h"
using namespace std;

class Robot {
protected :
    string type;
public:
    Robot(string type) {
        this->type = type;
    }
    virtual void display(int x , int y) = 0;
};

class HumanRobot : public Robot {
public:
    HumanRobot(string type) : Robot(type) {

    }
    void display(int x , int y) {
        cout << "Human robot is at x " << x << " and y " << y << endl;
    }
};


class RobotDogs : public Robot {
public:
    RobotDogs(string type) : Robot(type) {

    }
    void display(int x , int y) {
        cout << "Robot dogs is at x " << x << " and y " << y << endl;
    }
};

static unordered_map<string , Robot*>typeRobotMap;

static class RobotFactory {
public:
static Robot* createRobot(string robotType) {
    if(typeRobotMap.find(robotType) != typeRobotMap.end()) {
        cout << robotType << " robot already created with common fields!" << endl;
        return typeRobotMap[robotType];
    } else if (robotType == "Human") {
        cout << robotType << " robot created with common fields!" << endl;
        Robot* humanRobot = new HumanRobot("Human");
        typeRobotMap[robotType] = humanRobot;
        return humanRobot;
    } else if (robotType == "RobotDog") {
        cout << robotType << " robot created with common fields!" << endl;
        Robot* robotDogs = new RobotDogs("Robot_dogs");
        typeRobotMap[robotType] = robotDogs;
        return robotDogs;
    } 
    return nullptr;
}
};

int main() {
    //its very expensive to create millions of objects with common parameters,as it takes up RAM space so we can optimise it by sharinng these fields with other objects
    Robot* humanRobot1 = RobotFactory::createRobot("Human");
    humanRobot1->display(0, 2);
    Robot* humanRobot2 = RobotFactory::createRobot("Human");
    humanRobot2->display(1 , 3);

    Robot* robotDogs1 = RobotFactory::createRobot("RobotDog");
    robotDogs1->display(2 , 3);
    Robot* robotDogs2 = RobotFactory::createRobot("RobotDog");
    robotDogs2->display(3 , 3);
}