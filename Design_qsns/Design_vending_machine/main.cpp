#include "../../bitsStd.h"
#include "vendingMachine.h"
#include "vendingMachineManager.h"
#include "denomination.h"
using namespace std;

int main() {

VendingMachine* vendingMachine = VendingMachine::getVendingMachineInstance();
VendingMachineManager* vendingMachineManager = VendingMachine::getVendingMachineManager();

vendingMachineManager->addProduct(1 , 20 , 20);
vendingMachineManager->addProduct(2, 30 , 30);
vendingMachineManager->addProduct(4, 2 , 10);

Denomination* denomination1 = new Coin(10);
Denomination* denomination2 = new Note(90);
Denomination* denomination3 = new Note(15);

vendingMachine->insertDenomination(denomination3);
Product* p1 = vendingMachine->pressButton(4);

if(p1 == nullptr) {
    cout << "No product obtained!" << endl;
    return 0;
}

int change1 = vendingMachine->returnChange(p1);

if(change1 == 0) {
    cout << "No value needs to be returned" << endl;
} 


Product* p2 = vendingMachine->pressButton(4);

if(p2 == nullptr) {
    cout << "No product obtained!" << endl;
    return 0;
}

int change2 = vendingMachine->returnChange(p1);

if(change2 == 0) {
    cout << "No value needs to be returned" << endl;
}

}