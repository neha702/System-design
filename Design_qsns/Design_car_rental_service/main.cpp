#include "../../bitsStd.h"
#include "car_rental_service.h"
#include "user.h"
#include "reservation.h"
using namespace std;

int main() {
    //considering for now it will just give the cars
    CarRentalService* carRentalService = CarRentalService::getInstance();
    RentalServiceManager* rentalServiceManager = CarRentalService::rentalServiceManagerInstance;

    Location* l1 = new Location("Delhi" , 110001);
    Location* l2 = new Location("Mumbai" , 400001);

    Vehicle* v1 = new Vehicle("Car1" , 1 , Status::AVAILABLE , VehicleType::FOUR_WHEELER , 20);
    Vehicle* v2 = new Vehicle("Car2" , 2 , Status::AVAILABLE , VehicleType::FOUR_WHEELER , 30);

    rentalServiceManager->addLocation(l1);
    rentalServiceManager->addLocation(l2);

    rentalServiceManager->addVehicle(v1);
    rentalServiceManager->addVehicle(v2);

    rentalServiceManager->assignVehicleToLocation(v1 , l1);
    rentalServiceManager->assignVehicleToLocation(v2 , l2);

    Observer* emailNotiifier = new EmailNotiifer();
    Observer* smsNotifier = new SMSNotiifer();

    rentalServiceManager->addObserver(emailNotiifier);
    rentalServiceManager->addObserver(smsNotifier);

    User* user1 = new User("Neha", "nehaz702@gmail.com");
    User* user2 = new User("Rahul" , "rahul@gmail.com");
    vector<Vehicle*>vehiclesList1 = carRentalService->getVehiclesByLocation(l1);

    if(vehiclesList1.size() == 0) {    
        cout << "No vehicles available at location " << l1->getCity() << endl;
        return 0;
    }
    Reservation* reservation1 = new Reservation(1 , user1 , vehiclesList1[0] , l1 , l2 , 30); // choosen 1st vehicle
    cout << "Vehicle " << v1->getVehicleId() << " chosen by user " << user1->getUserName() << endl;
    carRentalService->bookVehicle(reservation1);

    PaymentStrategy* paymentStrategy = new PayByUPI();
    carRentalService->performPayment(reservation1 , paymentStrategy);

    rentalServiceManager->removeObserver(emailNotiifier);

    carRentalService->notify(reservation1);


    // vector<Vehicle*>vehiclesList2 = carRentalService->getVehiclesByLocation(l1);
    // if(vehiclesList2.size() == 0) {
    //     cout << "No vehicles available at location " << l1->getCity() << endl;
    //     return 0;
    // }
    // Reservation* reservation2 = new Reservation(2 , user2 , vehiclesList2[0] , l1 , l2 , 20); // choosen 1st vehicle
    // cout << "Vehicle " << v1->getVehicleId() << " chosen by user " << user2->getUserName() << endl;
    // carRentalService->bookVehicle(reservation2);

    carRentalService->returnVehicle(reservation1);



}