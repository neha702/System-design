#include "../bitsStd.h"
using namespace std;

class RoomVisitor;

class Room {
public:
    virtual void accept(RoomVisitor* roomVisitor) = 0;
};

class SingleRoom;
class DoubleRoom;
class DeluxeRoom;


class RoomVisitor {
public:
virtual void visit(SingleRoom* singleRoomObj) = 0;
virtual void visit(DoubleRoom* doubleRoomObj) = 0;
virtual void visit(DeluxeRoom* deluxeRoomObj) = 0;
};

class MaintenanceVisitor : public RoomVisitor {
public:
void visit(SingleRoom* singleRoombj) {
    cout << "Peforming maintenance of single room." << endl;
}

void visit(DoubleRoom* doubleRoombj) {
    cout << "Peforming maintenance of double room." << endl;
}

void visit(DeluxeRoom* deluxeRoombj) {
    cout << "Peforming maintenance of deluxe room." << endl;
}
};

class PricingVisitor : public RoomVisitor {
public:
void visit(SingleRoom* singleRoombj) {
    cout << "Peforming pricing computation of single room." << endl;
}

void visit(DoubleRoom* doubleRoombj) {
    cout << "Peforming pricing computation of double room." << endl;
}

void visit(DeluxeRoom* deluxeRoombj) {
    cout << "Peforming pricing computation of deluxe room." << endl;
}
};


class SingleRoom : public Room {
public:
void accept(RoomVisitor* roomVisitor) {
    roomVisitor->visit(this);
}
};

class DoubleRoom : public Room {
public:
void accept(RoomVisitor* roomVisitor) {
    roomVisitor->visit(this);
}
};

class DeluxeRoom : public Room {
public:
void accept(RoomVisitor* roomVisitor) {
    roomVisitor->visit(this);
}
};


int main() {
Room* singleRoomObj = new SingleRoom();
Room* doubleRoomObj = new DoubleRoom();

RoomVisitor* pricingVisitor = new PricingVisitor();
singleRoomObj->accept(pricingVisitor);

RoomVisitor* maintenanceVisitor = new MaintenanceVisitor();
doubleRoomObj->accept(maintenanceVisitor);
}