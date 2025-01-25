#include "../bitsStd.h"
using namespace std;

//Memento
class Memento {
string state;
public:
Memento(string newState) {
state = newState;
}

string getState() {
return state;
}
};


//Originator
class Originator {
string state;
public:
void setState(string newState) {
    state = newState;
}

string getState() {
    return state;
}

Memento saveStateToMemento() {
return Memento(state);
}

void restoreStateFromMemento(Memento* memento) {
    state = memento->getState();
}
};

//caretaker
class Caretaker{
vector<Memento*> mementoList;
public:
void addMemento(Memento* memento) {
    mementoList.push_back(memento);
}

Memento* getMemento(int ind) {
    if(ind >= 0 && ind < mementoList.size()) return mementoList[ind];
    return nullptr;
}
};



int main() {
Originator* originator = new Originator();
Caretaker* caretaker = new Caretaker();

originator->setState("v1");
Memento memento1 = originator->saveStateToMemento();
caretaker->addMemento(&memento1);

originator->setState("v2");
Memento memento2 = originator->saveStateToMemento();
caretaker->addMemento(&memento2);

Memento* histMemento1 = caretaker->getMemento(0);
if(histMemento1 == nullptr) cout << "History memento at that particular index doesn't exist!" <<endl;
originator->restoreStateFromMemento(histMemento1);

cout << originator->getState() << endl;
}