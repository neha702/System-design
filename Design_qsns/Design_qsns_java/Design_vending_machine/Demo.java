package Design_qsns.Design_qsns_java.Design_vending_machine;
import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.*;

/*
 Requirements:
 1. Vending machine would accept coins and notes.
 2. Vending machine can be used one at a time
 3. A person can cancel transaction halfway and still getback the money and return to idle state.
 5. A person will insert denomination , select porduct , product will be dispensed and change will be returned.
 6. A person can view his balance at any time.
 7. A person can enter multiple coins and has the opportunity to choose a product and then change it.
 8. All computation of money to be deducted on vending machine for product will happen while dispensing the product.
 9. After cancellation and dispense changing state changes to idle only.
 */
public class Demo {
    public static void main(String []args) {
        VendingMachineSvc svcInstance = VendingMachineSvc.getInstance();
        ProductService productSvcInstance = svcInstance.getProductServiceInstance();

        if(productSvcInstance == null){
            System.out.println("Product Service instance is null, cannot proceed.");
            return;
        }

        Product product1 = new Product("P001" , 10 , "Pepsi" , 2);
        Product product2 = new Product("P002" , 20 , "Lays" , 2);

        productSvcInstance.addProduct(product1);
        productSvcInstance.addProduct(product2);


        //Transaction1
        User u1 = new User("neha" , 1);
        u1.setBalance(100);
        if(!svcInstance.insertDenomination(10 , "NOTES" , u1)) return ; //90
        if(!svcInstance.insertDenomination(20 , "NOTE" , u1)) return;  //70  => total 30 in vending machine
        Product selected_product1 = svcInstance.selectProduct("P001"); //20 -> v balance
        if(selected_product1 != null) { // How we handle select_product1 that is invalidated now
            svcInstance.dispenseProduct(selected_product1);
            int change = svcInstance.dispenseChange(selected_product1 , u1); 
            if(change != -1) {
                System.out.println("Change is returned of amount: " + change); 
            }
        }
        //Transaction2
        if(svcInstance.cancelTransaction(u1)) return;
        svcInstance.viewBalances(u1);


        // User u2 = new User("rohan" , 2);
        // u2.setBalance(105);
        // svcInstance.viewBalances(u2);
    }
}
