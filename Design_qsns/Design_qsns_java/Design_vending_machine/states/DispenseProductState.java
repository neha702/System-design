package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.BalanceService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.ProductService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.StateService;

public class DispenseProductState implements State{
    public boolean insertValue(IDenomination value , User u , BalanceService balanceSvc, StateService stateSvc) {
        System.out.println("Can't insert value in dispense change state");
        return false;
    }

    public Product selectProduct(String productId , ProductService productSvc , StateService stateSvc , BalanceService balanceSvc) {
        System.out.println("Can't insert value in dispense change state");
        return null;
    }

    public boolean dispenseProduct(Product product , BalanceService balanceSvc , StateService stateSvc , ProductService productSvc) {
        System.out.println("Can't insert value in dispense change state");
        return false;
    }

    public int returnChange(Product product , User u , BalanceService balanceSvc , StateService stateSvc) {
        int change = balanceSvc.getBalance();
        u.setBalance(change);
        stateSvc.setState(new IdleState());
        System.out.println("Change returned: " + change);
        return change;
    }

    public boolean cancelTransaction(User u , BalanceService balanceSvc , StateService stateSvc) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(balanceSvc.getBalance());
        balanceSvc.setBalance(-balanceSvc.getBalance());
        stateSvc.setState(new IdleState());
        return true;
    }
}
