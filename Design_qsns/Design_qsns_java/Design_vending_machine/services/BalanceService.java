package Design_qsns.Design_qsns_java.Design_vending_machine.services;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;

public class BalanceService {
    private int balance = 0;

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
}
