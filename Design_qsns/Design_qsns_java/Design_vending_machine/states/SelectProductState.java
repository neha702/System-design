package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.BalanceService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.ProductService;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.StateService;

public class SelectProductState implements  State {
    public boolean insertValue(IDenomination value , User u , BalanceService balanceSvc , StateService stateSvc) {
        System.out.println("Can't insert value in select product state");
        return false;
    }

    public boolean cancelTransaction(User u , BalanceService balanceSvc, StateService stateSvc) {
        System.out.println("Transaction cancelled in select product state");
        //Return money back to user and update balance in vending machine
        u.setBalance(balanceSvc.getBalance());
        balanceSvc.setBalance(-balanceSvc.getBalance());
        stateSvc.setState(new IdleState());
        return true;
    }

    public Product selectProduct(String productId , ProductService productSvc , StateService stateSvc , BalanceService balanceSvc) {
        if(productSvc.isProductAvailable(productId)) {
            Product product = productSvc.getProduct(productId);
            if(product.getPrice() > balanceSvc.getBalance()) {
                System.out.println("Product can't be selected with product id: " + productId + " due to insufficient balance");  
                return null;
            }
            System.out.println("Product is selected with product id: " + productId);
            return product;
        }
        System.out.println("Product is not available with product id: " + productId);
        return null;
    }

    public boolean dispenseProduct(Product product , BalanceService balanceSvc, StateService stateSvc , ProductService productSvc) {
        //reduce product quantity and if product is over , reduce user balance and balance from machine
        if(product == null) {
            System.out.println("Product is not selected to dispense");
            return false;
        }
        product.setQuantity(1);
        balanceSvc.setBalance(-product.getPrice());
        if(product.getQuantity() == 0) {
            productSvc.removeProduct(product);
        } 
        System.out.println("Product is dispensed");
        stateSvc.setState(new DispenseProductState());
        return true;
    }

    public int returnChange(Product product , User u , BalanceService productSvc , StateService stateSvc) {
        System.out.println("Can't return change in select product state");
        return -1;
    }
}
