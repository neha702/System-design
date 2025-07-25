package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingMachineSvc;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingSvcManager;

public class DispenseProductState implements State{
    public boolean insertValue (IDenomination denomination , User u , VendingMachineSvc instance) {
        System.out.println("Can't insert value in dispense change state");
        return false;
    }

    public Product selectProduct(String productId ,VendingMachineSvc instance , VendingSvcManager managerInstance) {
        System.out.println("Can't insert value in dispense change state");
        return null;
    }

    public boolean dispenseProduct(Product product ,VendingMachineSvc instance , VendingSvcManager managerInstance) {
        System.out.println("Can't insert value in dispense change state");
        return false;
    }

    public int returnChange(Product product , User u , VendingMachineSvc instance) {
        int change = instance.getBalance();
        u.setBalance(change);
        instance.setState(new IdleState());
        System.out.println("Change returned: " + change);
        return change;
    }

    public boolean cancelTransaction(User u , VendingMachineSvc instance) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(instance.getBalance());
        instance.setBalance(-instance.getBalance());
        instance.setState(new IdleState());
        return true;
    }
}
