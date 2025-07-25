package Design_qsns.Design_qsns_java.Design_vending_machine.services;

import Design_qsns.Design_qsns_java.Design_vending_machine.factory.CreateDenominationFactory;
import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.states.*;

public class VendingMachineSvc {
    private static VendingMachineSvc vendingMachineInstance = null;
    private VendingSvcManager vendingMachineManagerInstance = null;
    private CreateDenominationFactory denominationFactory = null;
    private int balance = 0;
    private State state = null;

    private VendingMachineSvc() {
        state = new IdleState();
        denominationFactory = new CreateDenominationFactory();
        vendingMachineManagerInstance = new VendingSvcManager();
    }

    public VendingSvcManager getManagerInstance() {
        return vendingMachineManagerInstance;
    }

    public static VendingMachineSvc getInstance() {
        if(vendingMachineInstance == null) {
            synchronized (VendingMachineSvc.class) {
                if(vendingMachineInstance == null) {
                    vendingMachineInstance = new VendingMachineSvc();
                }
            }
        }
        return vendingMachineInstance;
    }

    public boolean insertDenomination(int amount , String denominationString , User u) {
        IDenomination denomination = denominationFactory.createDenominationFactory(amount, denominationString);
        if(denomination == null) {
            return false;
        }
        return state.insertValue(denomination , u , this);
    }

    public Product selectProduct(String productId) {
        return state.selectProduct(productId , this , vendingMachineManagerInstance);
    }

    public boolean dispenseProduct(Product product) {
        return state.dispenseProduct(product , this , vendingMachineManagerInstance);
    }

    public int dispenseChange(Product product , User u) {
        return state.returnChange(product ,u , this);
    }

    public boolean cancelTransaction(User u) {
        return state.cancelTransaction(u , this);
    }

    public void setBalance(int amount) {
        balance += amount; 
        System.out.println("Current balance of vending machine: " + balance);
    }

    public void viewBalances(User u) {
        System.out.println("Vending machine balance: " + balance + " , User balance: " + u.getBalance());
    }

    public  int getBalance() {
        return balance;
    }

    public void setState(State newState) {
        state = newState;
    }
}
