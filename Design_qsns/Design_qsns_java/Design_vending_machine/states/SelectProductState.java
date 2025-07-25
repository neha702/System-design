package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingMachineSvc;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingSvcManager;

public class SelectProductState implements  State {
    public boolean insertValue (IDenomination denomination , User u , VendingMachineSvc instance) {
        System.out.println("Can't insert value in select product state");
        return false;
    }

    public boolean cancelTransaction(User u , VendingMachineSvc instance) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(instance.getBalance());
        instance.setBalance(-instance.getBalance());
        return true;
    }

    public Product selectProduct(String productId , VendingMachineSvc instance , VendingSvcManager managerInstance) {
        if(managerInstance.isProductAvailable(productId)) {
            Product product = managerInstance.getProduct(productId);
            if(product.getPrice() > instance.getBalance()) {
                System.out.println("Product can't be selected with product id: " + productId + " due to insufficient balance");  
                return null;
            }
            System.out.println("Product is selected with product id: " + productId);
            instance.setState(new SelectProductState());
            return product;
        }
        System.out.println("Product is not available with product id: " + productId);
        return null;
    }

    public boolean dispenseProduct(Product product ,VendingMachineSvc instance , VendingSvcManager managerInstance) {
        //reduce product quantity and if product is over , reduce user balance and balance from machine
        if(product == null) {
            System.out.println("Product is not selected to dispense");
            return false;
        }
        product.setQuantity(1);
        instance.setBalance(-product.getPrice());
        if(product.getQuantity() == 0) {
           managerInstance.removeProduct(product);
        } 
        System.out.println("Product is dispensed");
        instance.setState(new DispenseProductState());
        return true;
    }

    public int returnChange(Product product , User u ,VendingMachineSvc instance) {
        System.out.println("Can't return change in select product state");
        return -1;
    }
}
