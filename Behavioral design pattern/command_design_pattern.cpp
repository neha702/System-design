#include "../bitsStd.h"
using namespace std;


//receiver
class airConditioner {
bool isOn = false;
public:
void turnOn() {
    isOn = true;
    cout << "AC is turned ON!" << endl;
}

void turnOff() {
    isOn = false;
    cout << "AC is turned OFF!" << endl;
}
};

//command interface
class ICommand {
public:
virtual void execute() = 0;
virtual void undo() = 0;
};

class TurnOffAC : public ICommand {
airConditioner* ac;
public:
TurnOffAC(airConditioner* ac) {
    this->ac = ac;
}

void execute() {
ac->turnOff();
}

void undo() {
ac->turnOn();
}
};

class TurnOnAC : public ICommand {
airConditioner* ac;
public:
TurnOnAC(airConditioner* ac) {
    this->ac = ac;
}

void execute() {
ac->turnOn();
}

void undo() {
ac->turnOff();
}
};

//invoker
class Remote {
stack<ICommand*>remote_stack;
ICommand* command;
public:

void setCommand(ICommand* command) {
    this->command = command;
    remote_stack.push(command);
}

void pressButton() {
    command->execute();
}

void undo() {
    if(!remote_stack.empty()) {
    ICommand* topCommand = remote_stack.top();
    remote_stack.pop();
    topCommand->undo();
    } else {
        cout << "No command that can be undone!" << endl;
    }
}
};

int main() {
airConditioner* ac = new airConditioner();
Remote* remote = new Remote();

remote->setCommand(new TurnOnAC(ac));
remote->pressButton();

remote->setCommand(new TurnOffAC(ac));
remote->pressButton();

remote->undo(); // ac turn off should be undone
remote->undo(); //ac turn on should be undone
remote->undo(); // should throw exception
}