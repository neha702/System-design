#include "../../bitsStd.h"
using namespace std;

#include "parking_lot.h"
#include "entrance.h"
#include "exit.h"
#include "parkingSpot_manager.cpp"


int main() {
    ParkingLot* parkingLot = ParkingLot::getParkingLot();
    ParkingSpotFactory* parkingSpotFactory = new ParkingSpotFactory();
    Vehicle* v1 = new Vehicle(1 , "Four_Wheeler");

    ParkingSpotManager* psManager = ParkingSpotManager::getParkingSpotManager();
    vector<ParkingSpot*>ParkingSpotList;
    psManager->addParkingSpot("Two_Wheeler",ParkingSpotList);
    psManager->addParkingSpot("Two_Wheeler",ParkingSpotList);
    psManager->addParkingSpot("Two_Wheeler" , ParkingSpotList);
    psManager->addParkingSpot("Four_Wheeler" , ParkingSpotList);

    Entrance* entrance = new Entrance(parkingSpotFactory);
    parkingLot->addEntrance(entrance);

    string vehicleType = v1->getVehicleType();
    ParkingSpot* parkingSpot1 = entrance->findParkingSpace(vehicleType , ParkingSpotList);
    if(parkingSpot1 == nullptr) {
        cout << "Parking space doesn't exist for this vehicle type!" << endl;
        return 0;
    }
    entrance->bookParkingSpot(parkingSpot1 , v1);
    Ticket* ticket1 = entrance->generateTicket(parkingSpot1);

    PriceStrategy* strategy = new HourlyPriceStrategy();
    CostComputorManager* costComputorManager = new CostComputorManager(strategy);
    PaymentFactory* paymentFactoryObj = new PaymentFactory();
    Payment* paymentObj = new Payment();

    Exit* exit = new Exit(costComputorManager , paymentFactoryObj , psManager , paymentObj);
    parkingLot->addExit(exit);

    exit->calculateParkingCost(ticket1 , strategy);
    exit->updateParkingSpot(ticket1);
    exit->makePayment(ticket1 , "CASH");

}