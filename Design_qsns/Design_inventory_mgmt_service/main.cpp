#include "../../bitsStd.h"
#include "inventoryService.h"
#include "warehouse.h"
#include "enums.h"

using namespace std;

int main() {
    InventoryService* inventoryService = InventoryService::getInstance();
    ProductFactory* productFactory = inventoryService->getProductFactory();

    Warehouse* wh1 = new Warehouse(1 , "Mahadevapura");
    Warehouse* wh2 = new Warehouse(2 , "Hoodi");
    inventoryService->addWarehouse(wh1);
    inventoryService->addWarehouse(wh2);
    
    Product* p1 = productFactory->createProduct("Biscuit1" ,1 , 12 , GROCERY , 5);
    Product* p2 = productFactory->createProduct("ExtensionBoard1" ,2 ,50 , ELECTRONICS , 3);
    Product* p3 = productFactory->createProduct("Pant1" ,3 , 13 , CLOTHING, 2);

    wh1->addProduct(p1, 6);
    wh2->addProduct(p2, 10);
    wh1->addProduct(p3, 5);
    
    inventoryService->checkInventory();

    //someone ordered something so product quantity need to be updated
    wh2->removeProduct(p2 , 5); //5
    wh1->removeProduct(p1, 2); //4
    wh1->removeProduct(p3 , 5); //0

    inventoryService->checkInventory();

    inventoryService->checkProductForReplenish(1);
}