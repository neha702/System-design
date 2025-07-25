package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingMachineSvc;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingSvcManager;

public class HasAmountState implements State {
    public boolean insertValue (IDenomination denomination , User u , VendingMachineSvc instance) {
        instance.setBalance(denomination.getAmount());
        u.setBalance(-denomination.getAmount());
        System.out.println("Denomination is inserted: " + denomination.getAmount());
        return false;
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
        instance.setState(new SelectProductState());
        return null;
    }

    public boolean cancelTransaction(User u , VendingMachineSvc instance) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(instance.getBalance());
        instance.setBalance(-instance.getBalance());
        instance.setState(new IdleState());
        return true;
    }

    public boolean dispenseProduct(Product product , VendingMachineSvc instance , VendingSvcManager managerInstance) {
        System.out.println("Can't dispense product in insert denomination state");
        return false;
    }

    public int returnChange(Product product , User u , VendingMachineSvc instance) {
        System.out.println("Can't return change in insert denomination state");
        return -1;
    }
}
