package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.BalanceService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.ProductService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.StateService;

public class HasAmountState implements State {
    public boolean insertValue(IDenomination denomination , User u , BalanceService balanceSvc , StateService stateSvc) {
        balanceSvc.setBalance(denomination.getAmount());
        u.setBalance(-denomination.getAmount());
        System.out.println("Denomination is inserted: " + denomination.getAmount());
        stateSvc.setState(new HasAmountState());
        return false;
    }

    public Product selectProduct(String productId , ProductService productSvc , StateService stateSvc , BalanceService balanceService) {
        if(productSvc.isProductAvailable(productId)) {
            Product product = productSvc.getProduct(productId);
            if(product.getPrice() > balanceService.getBalance()) {
                System.out.println("Product can't be selected with product id: " + productId + " due to insufficient balance");  
                return null;
            }

            System.out.println("Product is selected with product id: " + productId);
            stateSvc.setState(new SelectProductState());
            return product;
        }
        System.out.println("Product is not available with product id: " + productId);
        stateSvc.setState(new SelectProductState());
        return null;
    }

    public boolean cancelTransaction(User u , BalanceService balanceSvc , StateService stateSvc) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(balanceSvc.getBalance());
        balanceSvc.setBalance(-balanceSvc.getBalance());
        stateSvc.setState(new IdleState());
        return true;
    }

    public boolean dispenseProduct(Product product ,BalanceService balanceService  , StateService stateSvc , ProductService productSvc) {
        System.out.println("Can't dispense product in insert denomination state");
        return false;
    }

    public int returnChange(Product product , User u , BalanceService balanceSvc , StateService stateSvc) {
        System.out.println("Can't return change in insert denomination state");
        return -1;
    }
}
