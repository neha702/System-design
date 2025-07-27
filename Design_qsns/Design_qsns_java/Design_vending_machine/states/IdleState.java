package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.BalanceService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.ProductService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.StateService;

public class IdleState implements State{
    public boolean insertValue(IDenomination denomination , User u , BalanceService balanceSvc , StateService stateSvc) {
        balanceSvc.setBalance(denomination.getAmount());
        u.setBalance(-denomination.getAmount());
        System.out.println("Denomination is inserted: " + denomination.getAmount());
        stateSvc.setState(new HasAmountState()); 
        return true;
    }

    public boolean cancelTransaction(User u , BalanceService balanceSvc, StateService stateSvc) {
        System.out.println("Transaction can't be cancelled in idle state");
        return false;
    }

    public Product selectProduct(String productId , ProductService productSvc , StateService stateSvc , BalanceService balanceSvc) {
        System.out.println("Can't select product in idle state");
        return null;
    }

    public boolean dispenseProduct(Product product , BalanceService balanceSvc , StateService stateSvc ,ProductService productSvc) {
       System.out.println("Can't dispense product in idle state");
       return false;
    }

    public int returnChange(Product product , User u , BalanceService balanceSvc , StateService stateSvc) {
        System.out.println("Can't return change in idle state");
        return -1;
    }

}

// public boolean insertValue(int amount , String denominationType); // false for not allowed situation
// public Product selectProduct(int productId);  //null for not allowed situation or or no product found
// public boolean dispenseProduct(Product product); // false for not allowed situation
// public boolean cancelTransaction(); // false for not allowed situation
// public int returnChange(Product product); // -1 for  not allowed situation
